#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"
//#include "menu.h"

using namespace std;

//add dish function - will need to make a function for each subclasse since dish is an abstract class
void addMains(dish ** order, int * currentDishes, mains * addedMains, double dishCost, double * totalCost) {
	order[*currentDishes] = addedMains;
	*currentDishes = *currentDishes + 1;
	*totalCost = *totalCost + dishCost;
	cout << addedMains->getName() << " successfully added to order!\n";
}

//cancel a specific dish function
void cancelDish(dish ** order, int dishIndex, int * currentDishes, double dishCost, double * totalCost) {
	int tempIndex = dishIndex; 
	int remainder = *currentDishes - dishIndex; //number of remainder dishes after dish to be cancelled in the order array

	//reshuffling the order array
	int i;
	for (i=0; i<remainder; i++) {
		order[tempIndex] = order[tempIndex+1];
		tempIndex++;
	}

	*currentDishes = *currentDishes - 1; //because deleted a dish
	*totalCost = *totalCost - dishCost;
}