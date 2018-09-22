#ifndef DESSERT_H
#define DESSERT_H

#include "dish.h"
#include <string>

class dessert: public dish { //inherits from dish class
	static int numDesserts; //keeps track of how many dessert objects created
	std::string sweetness;

public:
	//default constructor - delete if not used
	dessert();

	//constructor taking arguments
	dessert(std::string dishName, double regPrice, std::string allergyInfo, std::string dSweetness);

	//getters
	std::string howSweet();

	//display function?

	//default deconstructor
	~dessert();
};

#endif