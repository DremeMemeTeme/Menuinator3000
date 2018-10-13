#include "menu.h"
#include "mainsmenu.h"
#include <string>
#include <iostream>
#include "mains.h"
#include "dish.h"

using namespace std;

mainsmenu::mainsmenu() : menu() {
	mainsArray = new mains[maxItems];
	//maxItems initialized in menu()
}

mainsmenu::mainsmenu(std::string menuTitle, int numOfItems) : menu(menuTitle, numOfItems) {
	mainsArray = new mains[maxItems];
	//maxItems initialized in menu constructor
}

void mainsmenu::addDish(mains dish) {
	if (dishCount < maxItems) {
		mainsArray[dishCount] = dish;
		dishCount++;
	}
}

mains mainsmenu::getMainsMenuItem(int i) {
	return mainsArray[i];
}

//deconstructor
mainsmenu::~mainsmenu() {
	delete[] mainsArray; //since allocated by new
}