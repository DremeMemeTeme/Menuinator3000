#include "menu.h"
#include "dish.h"
#include "dessert.h"
#include "dessertsmenu.h"
#include <string>
#include <iostream>

using namespace std;

dessertsmenu::dessertsmenu() : menu() {
	maxDessertItems = 10;
	dessertsArray = new desserts[maxDessertItems];
	dessertDishCount = 0;
}

dessertsmenu::dessertsmenu(string menuTitle, int numOfDessertItems) : menu(menuTitle) {
	maxItems = numOfItems;
	dessertsArray = new desserts[maxDessertItems];
	dishCount = 0;
}

void dessertsmenu::addDish(desserts dish) {
	if(dessertDishCount < maxDessertItems){
		dessertsArray[dessertDishCount] = dish;
		dessertDishCount++;
	}
}

desserts dessertsmenu::getDessertsMenuItem(int i) {
	return dessertsArray[i];
}

int dessertsmenu::getMax() {
	return maxDessertItems;
}

int dessertsmenu::getDishCount() {
	return dessertDishCount;
}

dessertsmenu::~dessertsmenu() {
	delete[] dessertsArray; //since allocated by new
}






