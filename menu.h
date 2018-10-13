#ifndef MENU_H
#define MENU_H

#include <string>
#include "dish.h"

class menu 
{
	//variables
	//dish ** dishArray;  //object arrays declared in subclasses bc need to hold specific objects
	std::string menuName; 
	int maxItems; //max number of dishes you can add to menu (not order)
	//std::string dishType; - commented out since adding subclasses
	int dishCount;

public: 
	//constructor
	menu();
	menu(std::string menuTitle, int numOfItems);

	//behaviour
	virtual void addDish(dish * food) = 0; //pure virtual - each subclass has a different function for this

	//getter
	//std::string getDishName(int i);  -> moved to subclasses
	std::string getMenuName();
	int getMax();  //max number of dishes you can add to menu 
	int getDishCount(); //returns current number of dishes in the menu
	//dish * getMenuItem(int i); //returns a pointer to a food item in the menu - will be included in subclasses

	//setter
	void setName(std::string newName); //gives a menu name to main, desserts, dinks menu

	~menu();

};

#endif