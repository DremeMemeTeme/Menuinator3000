#ifndef DRINKMENU_H
#define DRINKMENU_H

#include <string>
//#include <iostream>
#include "menu.h"
#include "dish.h"
#include "drink.h"

class drinkmenu : public menu {
	drink * drinkArray;
	int maxDrinkItems; 
	int drinkDishCount;

public:
	//default constructor
	drinkmenu();

	//constructor taking arguments
	drinkmenu(std::string menuTitle, int numOfDrinkItems);

	//getters
	dirnk getDrinkMenuitem(int i); //function to access desserts objects within the menu array
	int getMax();
	int getDishCount(); 

	//void displayDrinkMenu() //put displaydrink() from V_functions2.cpp here when it's finished?

	void addDish(drink dish);  //adds drink to the menu

	//default deconstrucotor
	~drinkmenu();
};

#endif