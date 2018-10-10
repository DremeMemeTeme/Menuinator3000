#include <string>
#include <iostream>
#include <string.h>
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

void addDessert(dish ** order, int * currentDishes, dessert * addedDessert, double * totalCost) {
	order[*currentDishes] = addedDessert;
	*currentDishes = *currentDishes + 1;
	*totalCost = *totalCost + addedDessert->getPrice();
	cout << addedDessert->getName() << " successfully added to order!\n";
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

//find a match between user input and item in order array
int findDishInOrder(string inputtedName, dish ** orderArray, int currentDishes) {
	int i;
	for (i=0; i<currentDishes; i++) {
		//if match found between user input and a dish name in the order array:
		if (strcasecmp(inputtedName.c_str(), (orderArray[i]->getName()).c_str()) == 0) {
			return i; //returns index of match in orderArray
		}
	}

	return -1; //ie match not found
}

void displayCurrentOrder(dish ** orderArray, int currentDishes, double totalCost) {
	//cout << "Your current order is: \n"; //or have this step in main rather than here?
	int i;
	for (i=0; i<currentDishes; i++) {
		cout << orderArray[i]->getName() << "........$" << orderArray[i]->getPrice() << "\n"; 
		//maybe add a "entree size" bool property to mains object, so can have an if loop about which price to display?
	}

	//cout << "Your current total cost is $" << totalCost << "\n"; //could have this step in main too
}