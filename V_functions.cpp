#include <iostream>
#include <string>
using namespace std;

extern void displayOptions();
extern void displayMain(int mainSize, string menuArray[], double menuPriceArray[]);
extern void displayDrinks(int drinksSize, string drinksArray[], double drinksPriceArray[]);
extern void displayDessert(int dessertSize, string dessertArray[], double dessertPriceArray[]);
extern void displayError();


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


