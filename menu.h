#ifndef MENU_H
#define MENU_H

#include <string>
#include "dish.h"

class menu 
{
	//variables
	dish ** dishArray;  // holds the differnt objects, probably should make this dynamic
	std::string menuName; 
	int maxItems; //max number of dishes you can add to menu (not order)
	std::string dishType; 
	int dishCount;

public: 
	//constructor
	menu();
	menu(std::string menuTitle, std::string itemType, int numOfItems);

	//behaviour
	void addDish(dish food); //add main,drinks,dessert objects into menu 

	//getter
	std::string getDishName();  
	int getMax();  //max number of dishes you can add to menu 

	//setter
	void setName(std::string newName); //gives a menu name to main, desserts, dinks menu

	~menu();

};

#endif