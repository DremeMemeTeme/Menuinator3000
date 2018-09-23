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
	std::string getDishPairing();

	//display function? or in menu object

	//default deconstructor
	~drink();
};

#endif