#ifndef DISH_H
#define DISH_H

#include <string>

class dish {
	std::string name;
	int price; //price of regular size
	std::string allergens; //lists common allergens present in food

public:
	//default constructor
	dish();

	//constructor taking arguments
	dish(std::string dishName, int regPrice, std::string allergyInfo);

	//getters
	getName();
	virtual getPrice(); //different function for the subclasses
}	