#ifndef MAINSMENU_H
#define MAINSMENU_H

#include <string>
//#include <iostream> //depending on if needed for display menu functions?
#include "menu.h"
#include "dish.h"
#include "mains.h"

class mainsmenu : public menu { //inherits from menu class
	mains * mainsArray; //menu array to hold mains dishes
	int maxItems; //max items for mains array
	int dishCount; //if this variable is in the menu class then it's difficult to access, since it's "private"

public: 
	//default constructor
	mainsmenu();

	//constructor taking arguments
	mainsmenu(std::string menuTitle, int numOfItems);


	//getters
	mains getMainsMenuItem(int i); //function to access mains objects within the menu array
	int getMax(); //returns max items for menu - Had to put it in subclass bc otherwise it was difficult to access (since in private for menu class)
	int getDishCount(); //returns current number of dishes in the menu

	//void displayMainsMenu() //put the display menu function here! can display name, price, allergens etc in this function

	void addDish(mains dish); //add mains to menu - because only adding mains objects, don't need to use pointers
	//although I haven't decided yet if it would be easier to use pointers to keep it consistent with the order array.....

	//default deconstructor
	~mainsmenu();
};

#endif