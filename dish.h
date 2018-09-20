#ifndef DISH_H
#define DISH_H

#include <string>

class dish {
	std::string name;
	double price;
	std::string allergens;

public:
	//default constructor - if we don't use this at all, will need to delete it
	dish();
	//constructor taking arguments
	dish(std::string dishName, double regPrice, std::string allergyInfo);

	//getters
	std::string getName();
	double getPrice();
	std::string getAllergens();

	//no setters because won't be using the default deconstructor in the main program

	//default deconstructor
	~dish();
};

#endif