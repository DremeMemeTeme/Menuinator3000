#include <string>
#include "dish.h"

using namespace std;

dish::dish() {
	name = "?";
	price = 0;
	allergens = "?";
}

dish::dish(string dishName, double regPrice, string allergyInfo) {
	name = dishName;
	price = regPrice;
	allergens = allergyInfo;
}

string dish::getName() {
	return name;
}

//implementation of base getprice function
double dish::getPrice() {
	return price;
}

string dish::getAllergens() {
	return allergens;
}

//default deconstructor
dish::~dish() {
	//delete any memory allocated by new
}