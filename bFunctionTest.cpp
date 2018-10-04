#include <string>
#include <iostream>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"

using namespace std;

extern void addDish(dish * order, int * currentDishes, dish addedDish, double dishCost, double * totalCost);
extern void cancelDish(dish * order, int dishIndex, int * currentDishes, double dishCost, double * totalCost);

int main() {
	mains spag = mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains sandwich = mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains curry = mains("Vindaloo", 18.9, "no allergens", 15.8, true);
	mains salad = mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains pasta = mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

	int currentDishes = 0; //for counting how many dishes currently in order
	int * currentDishesPtr = &currentDishes;
	int maxDishes = 10;
	dish * order = new dish[maxDishes];
	double totalCost = 0.0; //initializing total cost variable
	double * totalCostPtr = &totalCost;

	double dishCost = spag.getPrice(); //assuming the customer only wants to order mains
	addDish(order, currentDishesPtr, spag, dishCost, totalCostPtr);

	cout << "Current dishes: " << currentDishes << "\n"; //for debugging purposes

	double dishCost = sandwich.getPrice(); 
	addDish(order, currentDishesPtr, sandwich, dishCost, totalCostPtr);

	cout << "Current dishes: " << currentDishes << "\n"; 

	double dishCost = curry.getPrice(); 
	addDish(order, currentDishesPtr, curry, dishCost, totalCostPtr);

	cout << "Current dishes: " << currentDishes << "\n"; 

	double dishCost = salad.getPrice(); 
	addDish(order, currentDishesPtr, salad, dishCost, totalCostPtr);

	cout << "Current dishes: " << currentDishes << "\n"; 
}