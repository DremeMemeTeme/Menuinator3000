#ifndef MENU_H
#define MENU_H


#include <string>
#include "dish.h"

class menu 
{
	//variables
	int itemCount;  //number of items ordered
	std::string itemName; //name of dish added




public: 
	//constructor
	menu();
	menu(<inser_parameters_here>);

	//behaviour
	void addDish();
	int viewMenuContent();   //displays/prints all the food/dirnk items 
	                         //in the mains, dish, dessert classes
	

	//getter
	void orderCount();   //gets value of itemCount


	//setter


	~menu();


};

#endif