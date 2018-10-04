#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"

using namespace std;

extern void addMains(dish ** order, int * currentDishes, mains * addedMains, double dishCost, double * totalCost);
extern void cancelDish(dish ** order, int dishIndex, int * currentDishes, double dishCost, double * totalCost);

int main() {
	mains * spag = new mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains * sandwich = new mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains * curry = new mains("Vindaloo", 18.9, "no allergens", 15.8, true);
	mains * salad = new mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains * pasta = new mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

	int currentDishes = 0; //for counting how many dishes currently in order
	int * currentDishesPtr = &currentDishes;
	int maxDishes = 10;
	dish ** order = new dish * [maxDishes];
	double totalCost = 0.0; //initializing total cost variable
	double * totalCostPtr = &totalCost;

	double spagCost = spag->getPrice(); //assuming the customer only wants to order mains
	addMains(order, currentDishesPtr, spag, spagCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; //for debugging purposes

	double sandCost = sandwich->getPrice(); 
	addMains(order, currentDishesPtr, sandwich, sandCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	double curryCost = curry->getPrice(); 
	addMains(order, currentDishesPtr, curry, curryCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	double saladCost = salad->getPrice(); 
	addMains(order, currentDishesPtr, salad, saladCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	double pastaCost = pasta->getPrice(); 
	addMains(order, currentDishesPtr, pasta, pastaCost, totalCostPtr);

	cout << "Current dishes: " << currentDishes << "\n";

	cout << "Current total price: $" << totalCost << "\n"; //debugging purposes

	//can test match user input to array element function here

	//want to cancel sandwich - with index 1

	int cancelIndex = 1;

	cancelDish(order, cancelIndex, currentDishesPtr, sandCost, totalCostPtr);

	cout << sandwich->getName() << " successfully removed from order! Your order is now: \n";

	int j;
	for (j=0; j<currentDishes; j++) {
		cout << order[j]->getName() << "			\n";
	}

	cout << "Current total cost: $" << totalCost << endl;

	for (j=0; j<currentDishes; j++) {
		delete order[j];
	}

	delete sandwich;
	delete[] order;

	return 0;
}