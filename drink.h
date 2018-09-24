#ifndef DRINK_H
#define DRINK_H

#include "dish.h"
#include <string>

class drink : public dish {
	static int numDrinks;
	double glassPrice;
	double bottlePrice;
	std::string recommendedDish;

public:
	//default constructor - delete if not used in main
	drink();
	//constructor taking arguments
	drink(std::string dishName, double regPrice, double bPrice, std::string recomDish);

	//getters
	double getGlassPrice();
	double getBottlePrice();
	std::string getInfo(); //returns recommended dish pairing

	//default deconstructor
	~drink();
};

#endif