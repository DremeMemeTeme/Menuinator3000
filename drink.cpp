#include "dish.h"
#include "drink.h"
#include <string>

using namespace std;

//class variable
int drink::numDrinks = 0;

//default constructor 
drink::drink() : dish() {
	numDrinks++;
	//glassPrice = 0.0;
	bottlePrice = 0.0;
	type = "drink";
	recommendedDish = "?";
}

drink::drink(string dishName, double regPrice, double bPrice, string recomDish):dish(dishName, regPrice) {
	numDrinks++;
	price = regPrice;
	bottlePrice = bPrice;
	type = "drink";
	recommendedDish = recomDish;
}
/*
double drink::getGlassPrice() { //getGassPrice is the same as getPrice function (defined in dish class)
	return glassPrice;
}
*/
double drink::getBottlePrice() {
	return bottlePrice;
}

string drink::getInfo() {
	return recommendedDish;
}


//default deconstructor
drink::~drink() {
	//delete any memory allocated by new
}