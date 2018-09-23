#include "dish.h"
#include "drink.h"
#include <string>

using namespace std;

//class variable
int drink::numDrinks = 0;

//default constructor - delete if not used in main
drink::drink() : dish() {
	numDrinks++;
	glassPrice = 0.0;
	bottlePrice = 0.0;
	recommendedDish = "?";
}

drink::drink(string dishName, double regPrice, double bPrice, string recomDish):dish(dishName, regPrice, bPrice, recomDish) {
	numDrinks++;
	name = dishName;
	glassPrice = regPrice;
	bottlePrice = bPrice;
	recommendedDish = recomDish;
}

double drink::getGlassPrice() {
	return glassPrice;
}

double drink::getBottlePrice() {
	return bottlePrice;
}

string drink::getDishPairing() {
	return recommendedDish;
}

//display function, if including

//default deconstructor
drink::~drink() {
	//delete any memory allocated by new
}