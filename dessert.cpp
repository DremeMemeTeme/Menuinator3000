#include "dessert.h"
#include "dish.h"
#include <string>
//#include <iostream> - only if include display function

using namespace std;

int numDesserts = 0;

//default constructor - delete if don't use in main
dessert::dessert() : dish() {
	sweetness = "not sweet";
	numDesserts++;
}

dessert::dessert(string dishName, double regPrice, string allergyInfo, string dSweetness) : dish(string dishName, double regPrice, string allergyInfo) {
	sweetness = dSweetness;
	numDesserts++;
}

string dessert::howSweet() {
	return sweetness;
}

//display function? or maybe easier to write a generic display dish function for each subclass and call that separately

dessert::~dessert() {
	//delete any memory allocated by new
}