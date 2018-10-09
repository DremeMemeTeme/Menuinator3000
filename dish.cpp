#include <string>
#include "dish.h"

using namespace std;

dish::dish() {
	name = "?";
	price = 0;
	type = "?";
}

dish::dish(string dishName, double regPrice) {
	name = dishName;
	price = regPrice;
	type = "?";
	
}

string dish::getName() {
	return name;
}

double dish::getPrice() {
	return price;
}

string dish::getType() {
	return type;
}


//default deconstructor
dish::~dish() {
	//delete any memory allocated by new
}