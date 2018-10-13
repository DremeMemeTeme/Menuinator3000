/*
#include <iostream>
#include <string>
using namespace std;

extern void displayOptions();
extern void displayMain(int mainSize, string menuArray[], double menuPriceArray[]);
extern void displayDrinks(int drinksSize, string drinksArray[], double drinksPriceArray[]);
extern void displayDessert(int dessertSize, string dessertArray[], double dessertPriceArray[]);
extern void displayError();

-----------------------------------------------------------
[ OLD MAIN ]
int main(){

	string mainsMenu[] = {"Salad", "Chips", "Pasta", "Nachos", "GarlicBread"};
	string drinksMenu[] = {"Coke", "Beer", "icedTea"};
	string dessertMenu[] = {"Cake", "IceCream", "FruitSalad", "Candy", "Brownie"};

	double mainsPrice [] = {12.23, 4.98, 12.67, 5.67, 7.89};
	double drinksPrice[] = {5.78, 7.80, 3.55};
	double dessertPrice[] = {56.89, 34.67, 12.75, 17.89,43.87};


	int mainsCount = 5;  //number of items in the menu
	int drinksCount = 3; //number of items of drinks in drink menu
	int dessertCount = 5; //number of items in desserts menu


	//VARIABLES FOR USER INPUT
	string menuChoice;  //if user has to input a string/name of food/menu
	int choiceOption;   //if user has to input which option they would like to do next

 
	displayOptions();  //calls this function to print options
	cin >> choiceOption;

	int optionChosen = choiceOption;

	if(optionChosen == 1)
	{
		displayMain(mainsCount, mainsMenu, mainsPrice);	
	}
	if (optionChosen == 2)
	{
		displayDrinks(drinksCount, drinksMenu, drinksPrice);
	}
	if (optionChosen == 3)
	{
		displayDessert(dessertCount, dessertMenu, dessertPrice);
	}
	else if (optionChosen > 3 || optionChosen < 1)
	{
		displayError();
	}
}

-----------------------------------------------------------------------*/
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
extern bool displayInputError(string input, int maxNumOptions);
//extern displayMenu functions here
extern void displayOptions();
extern void displayMain(int mainSize, menu mainsMenu);


int main(){
	//some example dish objects created here:
	//mains:
	mains spag = mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains sandwich = mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains curry = mains("Vindaloo", 18.9, "no allergens", 15.8, true);
	mains salad = mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains pasta = mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

	displayMain(5, menu mainsMenu); 
	//just trying to test this funciton here with these objects


}





