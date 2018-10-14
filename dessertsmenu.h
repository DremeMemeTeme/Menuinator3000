#ifndef DESSERTSMENU_H
#define DESSERTSMENU_H

#include <string>
//#include <iostream>
#include "menu.h"
#include "dish.h"
#include "dessert.h"

class dessertsmenu : public menu {
	dessert * dessertsArray; //menu array to hold desserts dishes
	int maxDessertItems; //max items for mains array
	int dessertDishCount;

public:
	//default constructor
	dessertsmenu();

	//constructor taking arguments
	dessertsmenu(std::string menuTitle, int numOfDessertItems);

	//getters
	dessert getDessertsMenuItem(int i); //function to access desserts objects within the menu array
	int getMax(); //returns max items for menu
	int getDishCount(); //returns current number of dishes in the menu

	//void displayDessertsMenu()  //put displaydessert() from V_functions2.cpp here when it's finished?

	void addDish(dessert dish);  //adds desserts to the menu

	//default deconstrucotor
	~dessertsmenu();
};

#endif