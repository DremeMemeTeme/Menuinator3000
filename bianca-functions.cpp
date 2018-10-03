#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
//#include "menu.h"

//add dish function - may need to adapt for subclasses?
void addDish(dish * order, int * currentDishes, dish addedDish, double dishCost, double * totalCost) {
	order[currentDishes] = addedDish;
	currentDishes++;
	totalCost = totalCost + dishCost;
	cout << addedDish.getName() << " successfully added to order!\n";
}

