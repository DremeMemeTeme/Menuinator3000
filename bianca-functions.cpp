#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"
//#include "menu.h"

//add dish function - may need to adapt for subclasses?
void addDish(dish * order, int * currentDishes, dish addedDish, double dishCost, double * totalCost) {
	order[currentDishes] = addedDish;
	currentDishes++;
	totalCost = totalCost + dishCost;
	cout << addedDish.getName() << " successfully added to order!\n";
}

//cancel a specific dish function
void cancelDish(dish * order, int dishIndex, int * currentDishes, double dishCost, double * totalCost) {
	int tempIndex = dishIndex; 
	int sizeTempArray = currentDishes - dishIndex; //size needed for temp array
	//dish * tempArray = new dish[sizeTempArray]; //or should I create a menu object?

	//deleting specified dish
	delete order[dishIndex];

	//reshuffling the order array
	int i;
	for (i=0; i<sizeTempArray; i++) {
		order[tempIndex] = order[tempIndex+1];
		delete order[tempIndex+1];
		tempIndex++;
	}

	currentDishes--; //because deleted a dish
	totalCost = totalCost - dishCost;

	//delete[] tempArray (if I end up needing to use it)
}