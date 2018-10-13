#ifndef MAINSMENU_H
#define MAINSMENU_H

#include <string>
//#include <iostream> //depending on if needed for display menu functions?
#include "menu.h"
#include "dish.h"
#include "mains.h"

class mainsmenu : public menu { //inherits from menu class
	mains * mainsArray; //menu array to hold mains dishes

public: 
	//default constructor
	mainsmenu();

	//constructor taking arguments
	mainsmenu(std::string menuTitle, int numOfItems);

	//getters
	void addDish(mains dish); //add mains to menu - because only adding mains objects, don't need to use pointers
	mains getMainsMenuItem(int i); //function to access mains objects within the menu array
	//void displayMainsMenu() //put the display menu function here! can display name, price, allergens etc in this function

	//default deconstructor
	~mainsmenu();
};

#endif