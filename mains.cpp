#include "dish.h"
#include "mains.h"
#include <string>
#include <iostream>

using namespace std;

int mains::numMains = 0; //initializing the class variable

//default constructor - delete if don't use in main
mains::mains():dish() {
	numMains++;
	entreePrice = 0.0;
	spiciness = false;
}

mains::mains(string dishName, double regPrice, string allergyInfo, double mEntreePrice, bool spicy):dish(dishName, regPrice, allergyInfo) {
	numMains++;
	entreePrice = mEntreePrice;
	spiciness = spicy;
}
/*
double mains::getPrice() {
	return price;
}
*/
double mains::getEntreePrice() {
	return entreePrice;
}

bool mains::isSpicy() {
	return spiciness;
}

//display function?

//default deconstructor
mains::~mains() {
	//delete any memory allocated by new
}