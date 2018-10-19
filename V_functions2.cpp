#include <iostream>
#include <string>
using namespace std;
#include "menu.h"
#include "mains.h"
#include "mainsmenu.h"
#include "dish.h"
#include "drink.h"
#include "drinkmenu.h"
#include "dessert.h"
#include "dessertsmenu.h"

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
	cout << "\n" <<" What would you like to look at?" << '\n';
	cout <<"(Please enter the number of the menu you would like to look at)" << '\n';
	cout <<"(1) Mains Menu" << '\n';
	cout <<"(2) Drinks Menu" << '\n';
	cout <<"(3) Desserts Menu" << '\n';
}


//DISPLAYS MAIN MENU
void displayMain(mainsmenu * mainsMenu)
{
	cout << "\n" << "〖 ━━  HERE IS OUR MAINS MENU ━━ 〗:" << "\n";
		
	for(int i = 0; i<mainsMenu->getDishCount(); i++)
	{
		cout << "(" << i+1 << ")" << mainsMenu->getMainsMenuItem(i)->getName() <<
		 ".....(M)$" << mainsMenu->getMainsMenuItem(i)->getPrice() << 
		 ".....(E)$" << mainsMenu->getMainsMenuItem(i)->getDiffPrice() << "\n";
		 cout <<  "   ➩ Contains: " << mainsMenu->getMainsMenuItem(i)->getInfo() << "\n" << "\n";
	}	

	cout << " ◇────◇────◇────◇────◇────◇────◇────◇────◇────◇────◇" << "\n";
}

//DISPLAYS DRINKS MENU
void displayDrinks(drinkmenu * drinkMenu)
{
	cout << "\n" << "〖 ━━  HERE IS OUR DRINKS MENU ━━ 〗:" << "\n";
	for(int i=0; i<drinkMenu.getDishCount(); i++)
	{
		cout << "(" << i+1 << ")" << drinkMenu.getDrinkMenuItem(i)->getName() << 
		".....(G)$" << drinkMenu->getDrinkMenuItem(i)->getPrice() << 
		".....(B)$" << drinkMenu->getDrinkMenuItem(i)->getDiffPrice() << "\n";

		cout << "   ➩ Goes well with: " << drinkMenu->getDrinkMenuItem(i)->getInfo() << "\n" << "\n";
	}
	cout << " ◇────◇────◇────◇────◇────◇────◇────◇────◇────◇────◇" << "\n";
}


//DISPLAYES DESSERT MENU
void displayDessert(dessertsmenu * dessertsMenu)
{
	cout << "\n" << "〖 ━━  HERE IS OUR DESSERTS MENU ━━ 〗:" << "\n";
	for(int i=0; i<dessertsMenu.getDishCount(); i++)
	{
		cout << "(" << i+1 << ")" << dessertsMenu->getDessertsMenuItem(i)->getName() << 
		".....$" << dessertsMenu->getDessertsMenuItem(i)->getPrice() << "\n";

		cout << "   ➩ Contains: " << dessertsMenu->getDessertsMenuItem(i)->getInfo() << "\n";
		cout << "   ➩ Sweetness Level: " << dessertsMenu->getDessertsMenuItem(i)->howSweet() << "\n" << "\n";
	}
		cout << " ◇────◇────◇────◇────◇────◇────◇────◇────◇────◇────◇" << "\n";
}
/*
int main(){

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
	mainsmenu mainsMenu = mainsmenu("Mains Menu", 20);
	//--------------------
	mainsMenu.addDish(spag);
	mainsMenu.addDish(sandwich);
	mainsMenu.addDish(curry);
	mainsMenu.addDish(salad);
	mainsMenu.addDish(pasta);
	//--------------------

	dessertsmenu dessertsMenu = dessertsmenu("Dessert Menu", 15);
	//--------------------
	dessertsMenu.addDish(choc_cake);
	dessertsMenu.addDish(citrus_tart);
	//--------------------

	drinkmenu drinkMenu = drinkmenu("Drinks Menu", 15);
	//--------------------
	drinkMenu.addDish(white);
	drinkMenu.addDish(red);
	//--------------------

	displayOptions();

	int userInput;

	cin >> userInput;

	if(userInput == 1){
		displayMain(mainsMenu);
	}

	if(userInput == 2){
		displayDrinks(drinkMenu);
	}
	if(userInput == 3){
		displayDessert(dessertsMenu);
	}

	
	//delete[] mainsArray;
	return 0;
}
*/

/* -------------------------------------------------------------

If it helps find any errors, this is what I typed when
compiling it:

g++ -std=c++11 -o displayMain dish.cpp mains.cpp menu.cpp
mainsmenu.cpp drink.cpp drinkmenu.cpp dessert.cpp dessertsmenu.cpp
V-functions2.cpp

------------------------------------------------------------------*/



/*
//DISPLAYS ERROR MESSAGE
void displayError() //display error message
{
	cout << "Please enter a valid number" << '\n';
}

*/
