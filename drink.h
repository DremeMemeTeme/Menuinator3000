#ifndef DRINK_H
#define DRINK_H

#include "dish.h"
#include <string>

class drink : public dish {
	static int numDrinks;
	//double glassPrice; - glassPrice is equivalent to regular Price
	double bottlePrice;
	std::string recommendedDish;
	std::string type; //used for differentiating between subclasses

public:
	//default constructor 
	drink();
	//constructor taking arguments
	drink(std::string dishName, double regPrice, double bPrice, std::string recomDish);

	//getters
	//double getGlassPrice(); - equivalent to getPrice function defined in dish.h
	double getBottlePrice();
	std::string getInfo(); //returns recommended dish pairing
	std:: string getType();

	//default deconstructor
	~drink();
};

#endif