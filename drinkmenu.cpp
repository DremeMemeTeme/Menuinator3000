#include "menu.h"
#include "dish.h"
#include "drink.h"
#include "drinkmenu.h"
#include <string>
#include <iostream>

using namespace std;

drinkmenu::drinkmenu() : menu() {
	int maxDrinkItems = 10;
	drinkArray = new drink[maxDrinkItems];
	int drinkDishCount = 0;
}

drinkmenu::drinkmenu(string menuTitle, int numOfDrinkItems) : menu(menuTitle) {
	maxDrinkItems = numOfDrinkItems;
	drinkArray = new drink[maxDrinkItems];
	drinkDishCount = 0;
}

void drinkmenu::addDish(drink dish) {
		if(drinkDishCount < maxDrinkItems){
		drinkArray[drinkDishCount] = dish;
		drinkDishCount++;
	}
}

drink * drinkmenu::getDrinkMenuItem(int i) {
	return &drinkArray[i];
}

int drinkmenu::getMax() {
	return maxDrinkItems;
}

int drinkmenu::getDishCount() {
	return drinkDishCount;
}

//deconstructor
drinkmenu::~drinkmenu() {
	delete[] drinkArray; //since allocated by new
}




