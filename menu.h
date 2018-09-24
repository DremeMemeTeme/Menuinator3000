#ifndef MENU_H
#define MENU_H


#include <string>
#include "dish.h"


class menu 
{
	//variables
	dish menuCollection[15];  // holds the differnt objects, probably should make this dynamic
	std::string itemName;     //name of dish added
	std::string itemType;     //type of dish (main, drink or dessert)


public: 
	//constructor
	menu();
	menu(std::string itemName, double price);

	//behaviour
	void addDish(dish food); //add main,drinks,dessert objects into menu 

	//getter
	void dishName(); //

	~menu();


};

#endif