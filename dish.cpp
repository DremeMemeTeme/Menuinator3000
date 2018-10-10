#include <string>
#include "dish.h"

using namespace std;

dish::dish() {
	name = "?";
	price = 0;
}

dish::dish(string dishName, double regPrice) {
	name = dishName;
	price = regPrice;
	
}

string dish::getName() {
	return name;
}

double dish::getPrice() {
	return price;
}

double dish::getDiffPrice() { //won't use this function in main, but still has to be declared
	return 0; 
}


//default deconstructor
dish::~dish() {
	//delete any memory allocated by new
}