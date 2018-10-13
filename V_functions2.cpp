#include <iostream>
#include <string>
using namespace std;
#include "menu.h"
#include "mains.h"
#include "mainsmenu.h"

//DISPLAYS WHAT MENU YOU WANT TO VIEW
void displayOptions()
{
	cout <<"What would you like to look at?" << '\n';
	cout <<"(Please enter the number of the menu you would like to look at)" << '\n';
	cout <<"(1) Mains Menu" << '\n';
	cout <<"(2) Drinks Menu" << '\n';
	cout <<"(3) Desserts Menu" << '\n';
}


//DISPLAYS MAIN MENU
void displayMain(int mainSize, mainsmenu mainsMenu)
{
	int size = mainSize; //size corresponds to the number of items in both menu and price array

		cout << "HERE IS OUR MAINS MENU:" << '\n';
		/*
		for(int i=0; i<size; i++)
		{
			cout << "(" << i+1 << ")" << mains.getDishName(i) << "....." << "$ " << mains.getDiffPrice(i) << '\n'; 
		}	
		*/ //commented out for testing purposes - since it's not quite finished yet!
}






/*
//DISPLAYS DRINKS MENU
void displayDrinks(int drinksSize, string drinksArray[], double drinksPriceArray[])
{
	int size = drinksSize; //size corresponds to the number of items in both drinks and price array
	cout << "HERE IS OUR DRINKS MENU:" << '\n';
	for(int i=0; i<size; i++)
	{
		cout << drinksArray[i] << "....." << "$ " << drinksPriceArray[i] << '\n';
	}
}


//DISPLAYES DESSERT MENU
void displayDessert(int dessertSize, string dessertArray[], double dessertPriceArray[])
{
	int size = dessertSize; //size corresponds to the number of items in both drinks and price array
	cout << "HERE IS OUR DESSERT MENU:" << '\n';
	for(int i=0; i<size; i++)
	{
		cout << dessertArray[i] << "....." << "$ " << dessertPriceArray[i] << '\n';
	}
}

//DISPLAYS ERROR MESSAGE
void displayError() //display error message
{
	cout << "Please enter a valid number" << '\n';
}

*/
