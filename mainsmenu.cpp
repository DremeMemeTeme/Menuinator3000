#include "menu.h"
#include "mainsmenu.h"
#include <string>
#include <iostream>
#include "mains.h"
#include "dish.h"

using namespace std;

mainsmenu::mainsmenu() : menu() {
	maxItems = 10;
	mainsArray = new mains[maxItems];
	dishCount = 0;
	//maxItems initialized in menu()
}

mainsmenu::mainsmenu(string menuTitle, int numOfItems) : menu(menuTitle) {
	maxItems = numOfItems;
	mainsArray = new mains[maxItems];
	dishCount = 0;
}

void mainsmenu::addDish(mains dish) {
	if (dishCount < maxItems) {
		mainsArray[dishCount] = dish;
		dishCount++;
	}
}

mains * mainsmenu::getMainsMenuItem(int i) {
	return &mainsArray[i];
}

int mainsmenu::getMax() {
	return maxItems;
}

int mainsmenu::getDishCount() {
	return dishCount;
}

//deconstructor
mainsmenu::~mainsmenu() {
	delete[] mainsArray; //since allocated by new
}