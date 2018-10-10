#include "dish.h"
#include "mains.h"
#include <string>
#include <iostream>

using namespace std;

int mains::numMains = 0; //initializing the class variable

//default constructor 
mains::mains():dish() {
	numMains++;
	entreePrice = 0.0;
	spiciness = false;
	allergens = "?";
	//type = "mains";
	//size = "main"; //default size is main size
}

mains::mains(string dishName, double regPrice, string allergyInfo, double mEntreePrice, bool spicy):dish(dishName, regPrice) {
	numMains++;
	entreePrice = mEntreePrice;
	allergens = allergyInfo;
	spiciness = spicy;
	//type = "mains";
	//size = "main";
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

string mains::getInfo() {
	return allergens;
}
/*
string mains::getType() {
	return type;
}
*/
/*
string mains::getSize() {
	return size;
}

void mains::setSize(string dishSize) {
	size = dishSize;
}
*/
//default deconstructor
mains::~mains() {
	//delete any memory allocated by new
}