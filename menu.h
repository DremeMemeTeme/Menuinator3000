#ifndef MENU_H
#define MENU_H


#include <string>
#include "dish.h"


class menu 
{
	//variables
	dish * dishArray;  // holds the differnt objects, probably should make this dynamic
	std::string menuName; 
	int maxItems; //max number of dishes you can add



public: 
	//constructor
	menu();
	menu(std::string menuTitle, int numOfItems);

	//behaviour
	void addDish(dish food); //add main,drinks,dessert objects into menu 

	//getter
	std::string dishName();  
	int getMax(); 

	~menu();


};

#endif