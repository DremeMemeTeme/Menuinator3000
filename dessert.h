#ifndef DESSERT_H
#define DESSERT_H

#include "dish.h"
#include <string>

class dessert: public dish { //inherits from dish class
	static int numDesserts; //keeps track of how many dessert objects created
	std::string sweetness;
	std::string allergens;

public:
	//default constructor 
	dessert();

	//constructor taking arguments
	dessert(std::string dishName, double regPrice, std::string allergyInfo, std::string dSweetness);

	//getters
	std::string howSweet();
	std::string getInfo(); //returns allergen information

	//default deconstructor
	~dessert();
};

#endif