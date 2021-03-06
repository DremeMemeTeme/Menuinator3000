#ifndef DISH_H
#define DISH_H

#include <string>

class dish {
	std::string name;
	double price;
	std::string dishType; //placeholder var for subclass "type" variable
	

public:
	//default constructor - if we don't use this at all, will need to delete it
	dish();
	//constructor taking arguments
	dish(std::string dishName, double regPrice);

	//getters
	std::string getName();
	double getPrice();
	virtual double getDiffPrice(); //returns either entree or bottle price for mains or drinks
	virtual std::string getInfo() = 0; //pure virtual - returns allergen info or paired dish
	virtual std::string getType() = 0; //pure virtual - defined in subclasses

	//no setters because won't be using the default deconstructor in the main program

	//default deconstructor
	~dish();
};

#endif