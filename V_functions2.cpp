#include <iostream>
#include <string>
using namespace std;
#include "menu.h"
#include "mains.h"
#include "mainsmenu.h"
#include "dish.h"

/*
extern void addDish(mains dish);
extern int getDishCount();
extern int getMax();
extern mains getMainsMenuItem(int i);
*/
//extern mainsmenu(string menuTitle, int numOfItems);

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
void displayMain(int mainSize, mains a)
{
	int size = mainSize; //size corresponds to the number of items in both menu and price array

		cout << "HERE IS OUR MAINS MENU:" << "\n";
		
		for(int i=0; i<size; i++)
		{
			cout << "(" << i+1 << ")" << a.getName() << "....." << "$ " << a.getDiffPrice() << '\n'; 
		}	
}

/*
int main(){

	mains spag = mains("Spaghetti", 18.90, "gluten", 15.9, false);
	mains sandwich = mains("Sandwich", 7.9, "gluten, dairy", 4.50, false);
	mains curry = mains("Vindaloo", 18.9, "no allergens", 15.8, true);
	mains salad = mains("Ceasar Salad", 15.9, "gluten, egg", 12.9, false);
	mains pasta = mains ("Creamy Fettucine", 18.9, "gluten, dairy", 15.9, false);

 
	//creating & intitializing menus
	mainsmenu mainsMenu = mainsmenu("Mains Menu", 20);
	int maxDishes = 20;
	//mains * mainsArray = new mains[maxDishes];
	//--------------------
	mainsMenu.addDish(spag);
	mainsMenu.addDish(sandwich);
	mainsMenu.addDish(curry);
	mainsMenu.addDish(salad);
	mainsMenu.addDish(pasta);

	for(int i = 0; i<mainsMenu.getDishCount(); i++){
		cout << "(" << i+1 << ")" << mainsMenu.getMainsMenuItem(i)->getName() <<  "\n";
	}

	
	//displayMain(5, spag);

	//delete[] mainsArray;
	return 0;
}
*/




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
