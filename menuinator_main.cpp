#include <string>
#include <iostream>

#include <string.h>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"
#include "menu.h"

using namespace std;

extern void addMains(dish ** order, int * currentDishes, mains * addedMains, double * totalCost, char size, int * dishSizes);
extern void cancelDish(dish ** order, int dishIndex, int * currentDishes, double dishCost, double * totalCost, int * dishSizes);
extern int findDishInOrder(string inputtedName, dish ** orderArray, int currentDishes);
extern void displayCurrentOrder(dish ** orderArray, int currentDishes, double totalCost, int * dishSizes);
extern void addDessert(dish ** order, int * currentDishes, dessert * addedDessert, double * totalCost);
extern void addDrink(dish ** order, int * currentDishes, drink * addedDrink, double * totalCost, char size, int * dishSizes);
//extern displayMenu functions here


int main(){
	//some example dish objects created here:
	//mains:
	mains spag = mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains sandwich = mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains curry = mains("Vindaloo", 18.9, "no allergens", 15.8, true);
	mains salad = mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains pasta = mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

	//desserts:
	dessert choc_cake = dessert("Chocolate Cake", 5.50, "egg, gluten & dairy", "sweet");
	dessert citrus_tart = dessert("Citrus Tart", 5.50, "egg & gluten", "very sweet");

	//drinks:
	drink white = drink("House White", 6.40, 25.0, "Creamy Fettucine");
	drink red = drink("House Red", 6.40, 25.0, "Vindaloo");

	//creating & intitializing menus
	menu mainsMenu = menu("Mains Menu", "mains", 20);
	//--------------------
	mainsMenu.addDish(&spag);
	mainsMenu.addDish(&sandwich);
	mainsMenu.addDish(&curry);
	mainsMenu.addDish(&salad);
	mainsMenu.addDish(&pasta);
	//--------------------

	menu dessertMenu = menu("Dessert Menu", "dessert", 15);
	//--------------------
	dessertMenu.addDish(&choc_cake);
	dessertMenu.addDish(&citrus_tart);
	//--------------------

	menu drinkMenu = menu("Drinks Menu", "drink", 15);
	//--------------------
	drinkMenu.addDish(&white);
	drinkMenu.addDish(&red);
	//--------------------

	//creating order array
	int maxDishes = 20; //max dishes that customer can order
	dish ** orderArray = new dish * [maxDishes];
	int * dishSizes = new int[maxDishes]; //array for storing the sizes of dishes ordered

	int currentDishes = 0; //for counting how many dishes currently in order
	double totalCost = 0.0; //initializing total cost variable

	string input = "0"; //initializing customer input variable

	while (input != "quit") { //we can use "quit" or some other appropriate variable to cancel the whole order
		//prompting for user input goes here
	}




	delete[] orderArray;
	delete[] dishSizes;
	//delete any other memory allocated by new
	return 0;
}
