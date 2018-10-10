#include "dessert.h"
#include "dish.h"
#include <string>

using namespace std;

int dessert::numDesserts = 0;

//default constructor
dessert::dessert() : dish() {
	sweetness = "not sweet";
	allergens = "?";
	type = "dessert";
	numDesserts++;
}

dessert::dessert(string dishName, double regPrice, string allergyInfo, string dSweetness) : dish(dishName, regPrice) {
	sweetness = dSweetness;
	allergens = allergyInfo;
	type = "dessert";
	numDesserts++;
}

string dessert::howSweet() {
	return sweetness;
}

string dessert::getInfo() {
	return allergens;
}

string dessert::getType() {
	return type;
}
/*
double dessert::getDiffPrice() {
	return 0;
}
*/
dessert::~dessert() {
	//delete any memory allocated by new
}