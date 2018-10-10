#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"

using namespace std;

extern void addMains(dish ** order, int * currentDishes, mains * addedMains, double * totalCost, int size);
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

	int size = 0;
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	while (size < 1 || size > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addMains(order, currentDishesPtr, &spag, totalCostPtr, size);

	//cout << "Current dishes: " << currentDishes << "\n"; //for debugging purposes

	size = 0;
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	while (size < 1 || size > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addMains(order, currentDishesPtr, &sandwich, totalCostPtr, size);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	size = 0;
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	while (size < 1 || size > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addMains(order, currentDishesPtr, &curry, totalCostPtr, size);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	size = 0;
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	while (size < 1 || size > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addMains(order, currentDishesPtr, &salad, totalCostPtr, size);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	size = 0;
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	while (size < 1 || size > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addMains(order, currentDishesPtr, &pasta, totalCostPtr, size);

	cout << "Current dishes: " << currentDishes << "\n";

	cout << "Current total price: $" << totalCost << "\n"; //debugging purposes

	//can test match user input to array element function here

	cin.ignore(100, '\n'); //ignores newline character for cin input
	string cancelledDishName; //name of dish to be cancelled
	cout << "Please enter the name of the dish you want to cancel: ";
	getline(cin, cancelledDishName); //will take in dish name even if it is 2 words

	int cancelIndex;
	cancelIndex = findDishInOrder(cancelledDishName, order, currentDishes);

	while (cancelIndex == -1 && cancelledDishName != "c") {
		cout << "\nDish not found, please try again or type 'c' to cancel action: ";
		getline(cin, cancelledDishName);
		cancelIndex = findDishInOrder(cancelledDishName, order, currentDishes);
	}
	if (cancelledDishName != "c") {
		double dishCost = order[cancelIndex]->getPrice(); //
		string dishName = order[cancelIndex]->getName();

		cancelDish(order, cancelIndex, currentDishesPtr, dishCost, totalCostPtr);

		cout << dishName << " successfully removed from order! Your order is now: \n\n";

		displayCurrentOrder(order, currentDishes, totalCost);

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