#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"

using namespace std;

extern void addMains(dish ** order, int * currentDishes, mains * addedMains, double dishCost, double * totalCost);
extern void cancelDish(dish ** order, int dishIndex, int * currentDishes, double dishCost, double * totalCost);
extern int findDishInOrder(string inputtedName, dish ** orderArray, int currentDishes);
extern void displayCurrentOrder(dish ** orderArray, int currentDishes, double totalCost);

int main() {
	mains spag = mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains sandwich = mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains curry = mains("Vindaloo", 18.9, "no allergens", 15.8, true);
	mains salad = mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains pasta = mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

	int currentDishes = 0; //for counting how many dishes currently in order
	int * currentDishesPtr = &currentDishes;
	int maxDishes = 10;
	dish ** order = new dish * [maxDishes];
	double totalCost = 0.0; //initializing total cost variable
	double * totalCostPtr = &totalCost;

	double spagCost = spag.getPrice(); //assuming the customer only wants to order mains
	addMains(order, currentDishesPtr, &spag, spagCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; //for debugging purposes

	double sandCost = sandwich.getPrice(); 
	addMains(order, currentDishesPtr, &sandwich, sandCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	double curryCost = curry.getPrice(); 
	addMains(order, currentDishesPtr, &curry, curryCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	double saladCost = salad.getPrice(); 
	addMains(order, currentDishesPtr, &salad, saladCost, totalCostPtr);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	double pastaCost = pasta.getPrice(); 
	addMains(order, currentDishesPtr, &pasta, pastaCost, totalCostPtr);

	cout << "Current dishes: " << currentDishes << "\n";

	cout << "Current total price: $" << totalCost << "\n"; //debugging purposes

	//can test match user input to array element function here

	string cancelledDishName; //name of dish to be cancelled
	cout << "Please enter the name of the dish you want to cancel: ";
	getline(cin, cancelledDishName); //will take in dish name even if it is 2 words

	int cancelIndex;
	cancelIndex = findDishInOrder(cancelledDishName, order, currentDishes);

	if (cancelIndex != -1) {
		double dishCost = order[cancelIndex]->getPrice();
		string dishName = order[cancelIndex]->getName();

		cancelDish(order, cancelIndex, currentDishesPtr, dishCost, totalCostPtr);

		cout << dishName << " successfully removed from order! Your order is now: \n\n";

		displayCurrentOrder(order, currentDishes, totalCost);

	} else {
		cout << "Dish not found.\n";
	}
	
	cout << "\nCurrent total cost: $" << totalCost << endl;

	/*int k;
	for (k=0; k<currentDishes; k++) {
		delete order[k];
	}
	*/
	
	delete[] order;

	return 0;
}