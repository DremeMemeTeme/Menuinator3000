#ifndef DISH_H
#define DISH_H

#include <string>

class dish {
	std::string name;
	double price;

public:
	//default constructor - if we don't use this at all, will need to delete it
	dish();
	//constructor taking arguments
	dish(std::string dishName, double regPrice);

	//getters
	std::string getName();
	double getPrice();
	virtual std::string getInfo() = 0; //pure virtual - returns allergen info or paired dish

	//no setters because won't be using the default deconstructor in the main program

	//default deconstructor
	~dish();
};

#endif