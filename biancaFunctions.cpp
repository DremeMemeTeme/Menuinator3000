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
void addMains(dish ** order, int * currentDishes, mains * addedMains, double * totalCost, string size, int * dishSizes) {
	//cout << "current dishes value: " << *currentDishes << " item adding "<< addedMains->getName()<< "\n";
	int index = *currentDishes;
	order[index] = addedMains;
	//cout << "value at zeroth index " << order[0]->getName() << "\n"; //debugging

	
	switch (size[0] - '0') {
			case 1: //ie main size
			*totalCost = *totalCost + addedMains->getPrice();
			dishSizes[*currentDishes] = 0;
			//cout << "dishSizes value = " << dishSizes[*currentDishes] << "\n";
			*currentDishes = *currentDishes + 1;
			break;

			case 2: //ie entree size
			*totalCost = *totalCost + addedMains->getDiffPrice();
			dishSizes[*currentDishes] = 1;
			//cout << "dishSizes value = " << dishSizes[*currentDishes] << "\n";
			*currentDishes = *currentDishes + 1;
			break;
		}
		//cout << "value at zeroth index " << order[0]->getName() << "\n"; //debugging
	cout << addedMains->getName() << " successfully added to order!\n"; 
}

void addDessert(dish ** order, int * currentDishes, dessert * addedDessert, double * totalCost, int * dishSizes) {
	order[*currentDishes] = addedDessert;
	dishSizes[*currentDishes] = 0; //since no alternative size for desserts
	*currentDishes = *currentDishes + 1;
	*totalCost = *totalCost + addedDessert->getPrice();
	cout << addedDessert->getName() << " successfully added to order!\n";
}

void addDrink(dish ** order, int * currentDishes, drink * addedDrink, double * totalCost, string size, int * dishSizes) {
	order[*currentDishes] = addedDrink;
	
	switch (size[0] - '0') {
			case 1:
			*totalCost = *totalCost + addedDrink->getPrice();
			dishSizes[*currentDishes] = 0;
			*currentDishes = *currentDishes + 1;
			break;

			case 2:
			*totalCost = *totalCost + addedDrink->getDiffPrice();
			dishSizes[*currentDishes] = 1;
			*currentDishes = *currentDishes + 1;
			break;
		}
	cout << addedDrink->getName() << " successfully added to order!\n";
}

//cancel a specific dish function
void cancelDish(dish ** order, int dishIndex, int * currentDishes, double * totalCost, int * dishSizes) {
	int tempIndex = dishIndex; 
	string dishName = order[*currentDishes-1]->getName();
	int remainder = *currentDishes - dishIndex; //number of remainder dishes after dish to be cancelled in the order array
	double dishCost;
	if (dishSizes[dishIndex] == 1) {
		//entree/bottle size
		dishCost = order[dishIndex]->getDiffPrice(); 
	} else {
		//main size
		dishCost = order[dishIndex]->getPrice();
	}
	//reshuffling the order array
	int i;
	for (i=0; i<remainder; i++) {
		order[tempIndex] = order[tempIndex+1];
		dishSizes[tempIndex] = dishSizes[tempIndex+1]; //shuffles size array too
		tempIndex++;
	}

	*currentDishes = *currentDishes - 1; //because deleted a dish
	*totalCost = *totalCost - dishCost;

	cout << dishName << " successfully removed from order! Your order is now: \n\n";

	
}

//find a match between user input and item in order array
int findDishInOrder(string inputtedName, dish ** orderArray, int currentDishes) {
	int i;
	//cout << "current Dishes: " << currentDishes << "\n";
	for (i=0; i<currentDishes; i++) {
		//if match found between user input and a dish name in the order array:
		if (strcasecmp(inputtedName.c_str(), (orderArray[i]->getName()).c_str()) == 0) {
			//cout << "dish index: " << i << "\n";
			return i; //returns index of match in orderArray
		}
	}

	return -1; //ie match not found
}

void displayCurrentOrder(dish ** orderArray, int currentDishes, double totalCost, int * dishSizes) {
	//cout << "Your current order is: \n"; //or have this step in main rather than here?
	int i;
	for (i=0; i<currentDishes; i++) {
		cout << orderArray[i]->getName() << "........$"; 

		if (dishSizes[i] == 0) {
			cout << orderArray[i]->getPrice() << "\n"; 
		} else {
			cout << orderArray[i]->getDiffPrice() << "\n";
		}
		
	}

	cout << "\nYour current total cost is $" << totalCost << "\n\n"; //could have this step in main too
}

bool displayInputError(string input, int maxNumOptions) {
	if (input[0] - '0' < 1 || input[0] -'0' > maxNumOptions) {
		cout << "\nInvalid input! Please enter a number between 1 and " << maxNumOptions << ": ";
		return true;
	}
	return false;
}

bool quitCondition(string input) {
	string exitInput = "quit";
	int exitCondition = strcasecmp(input.c_str(), exitInput.c_str());

	if (exitCondition == 0) {
		cout << "Thanks for using the Menu-inator 3000! See you next time.\n";
		return true;
	} else {
		return false;
	}
}