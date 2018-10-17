#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"
#include "menu.h"
#include "mainsmenu.h"

using namespace std;

extern void addMains(dish ** order, int * currentDishes, mains * addedMains, double * totalCost, string size, int * dishSizes);
extern void cancelDish(dish ** order, int dishIndex, int * currentDishes, double * totalCost, int * dishSizes);
extern int findDishInOrder(string inputtedName, dish ** orderArray, int currentDishes);
extern void displayCurrentOrder(dish ** orderArray, int currentDishes, double totalCost, int * dishSizes);

int main() {
	mains spag = mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains sandwich = mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains curry = mains("Vindaloo", 18.9, "n/a", 15.8, true);
	mains salad = mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains pasta = mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

	int currentDishes = 0; //for counting how many dishes currently in order
	int * currentDishesPtr = &currentDishes;
	int maxDishes = 10;
	dish ** order = new dish * [maxDishes];
	int * dishSizes = new int[maxDishes]; //for storing sizes of dishes added
	double totalCost = 0.0; //initializing total cost variable
	double * totalCostPtr = &totalCost;

	mainsmenu mainsMenu("Mains Menu", 20);

	mainsMenu.addDish(spag);
	mainsMenu.addDish(sandwich);
	mainsMenu.addDish(curry);
	mainsMenu.addDish(salad);
	mainsMenu.addDish(pasta);

	string size = "0"; //as a char array (aka string) so that code doesnt break when chars entered instead of ints
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	
	while (size[0] - '0' < 1 || size[0] - '0' > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	mains addedMains = mainsMenu.getMainsMenuItem(1);
	addMains(order, currentDishesPtr, &addedMains, totalCostPtr, size, dishSizes);

	//cout << "Current dishes: " << currentDishes << "\n"; //for debugging purposes

	size = "0";
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	
	while (size[0] - '0' < 1 || size[0] - '0' > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addedMains = mainsMenu.getMainsMenuItem(2);

	addMains(order, currentDishesPtr, &addedMains, totalCostPtr, size, dishSizes);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	size = '0';
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	
	while (size[0] - '0' < 1 || size[0] - '0' > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addedMains = mainsMenu.getMainsMenuItem(3);

	addMains(order, currentDishesPtr, &addedMains, totalCostPtr, size, dishSizes);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	size = '0';
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	
	while (size[0] - '0' < 1 || size[0] - '0' > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addedMains = mainsMenu.getMainsMenuItem(4);

	addMains(order, currentDishesPtr, &addedMains, totalCostPtr, size, dishSizes);

	//cout << "Current dishes: " << currentDishes << "\n"; 

	size = '0';
	cout << "Please enter the number corresponding to the size you would like to order:\n";
	cout << "(1) Main\n" << "(2) Entree\n";
	cin >> size;
	 
	while (size[0] - '0' < 1 || size[0] - '0' > 2) {
		cout << "That is not a valid number! Please enter either 1 or 2: ";
		cin >> size;
	} 

	addedMains = mainsMenu.getMainsMenuItem(5);

	addMains(order, currentDishesPtr, &addedMains, totalCostPtr, size, dishSizes);

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

	double dishCost;

	if (cancelledDishName != "c") {
		if (order[cancelIndex]->getType() == "mains") {
			if (dishSizes[cancelIndex] == 1) {
				dishCost = order[cancelIndex]->getDiffPrice();
			} else {
			dishCost = order[cancelIndex]->getPrice();
			}
		} else if (order[cancelIndex]->getType() == "drink") {
			if (dishSizes[cancelIndex] == 1) {
				dishCost = order[cancelIndex]->getDiffPrice();
			} else {
				dishCost = order[cancelIndex]->getPrice();
			}
		} else {
			dishCost = order[cancelIndex]->getPrice();
		}
		
		string dishName = order[cancelIndex]->getName();

		cancelDish(order, cancelIndex, currentDishesPtr, totalCostPtr, dishSizes);

		cout << dishName << " successfully removed from order! Your order is now: \n\n";

		displayCurrentOrder(order, currentDishes, totalCost, dishSizes);

	} 
	
	cout << "\nCurrent total cost: $" << totalCost << endl;

	/*int k;
	for (k=0; k<currentDishes; k++) {
		delete order[k];
	}
	*/
	
	delete[] order;
	delete[] dishSizes;

	return 0;
}