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

	while (strcasecmp(input.c_str(), "quit") != 0) { //using strcasecmp so case insensitive
		/*
		cout << "Welcome to the Menuinator 3000! \nWhich menu would you like to look at today?\n";
		cout << "(1) Mains Menu\n";
		cout << "(2) Drinks Menu\n";
		cout << "(3) Dessert Menu\n";
		cout << "Please enter the number of the menu you would like to look at: ";
		*/

		//declaring all variables used within the following while loops here:
		string dishNum; //initializing "add dish" number variable - declared as a string to cope with possible char input
		int menuInput; //variable for deciding which menu to display - so that options don't get confused by only using "input"
		int mainsInput; 
		int dishIndex; //variable for the index of the dish to be added in the menu array
		mains * addedMains; //pointer to mains dish that user wants to add to order
		string size; //stores the size of the dish (eg entree vs mains)

		displayOptions(); //calling this shows user what menus are available
		cout << "Type 'quit' at any time to exit the program\n";
		cin >> input;

		int maxNumOptions = 3;
		bool inputError = displayInputError(input, maxNumOptions); 
		while ( inputError == true) {
			cin >> input;
			inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
		}

		menuInput = 0; 
		if (input == "1") {
			menuInput = 1;
		} 
		if (input == "2") {
			menuInput = 2;
		} 
		if (input == "3") {
			menuInput = 3;
		} 

		while (menuInput == 1) {
			//Display mains menu function
			cout << "What would you like to do next?\n";
			cout << "Please enter a number: \n";
			cout << "(1) Add dish to order\n";
			cout << "(2) Look at a different menu\n";
			cout << "Type 'quit' at any time to exit the program\n";
			cin >> input;
			maxNumOptions = 2;
			inputError = displayInputError(input, maxNumOptions);

			while ( inputError == true) {
				cin >> input;
				inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
			}
			mainsInput = 0;
			if (input == "1") {
				mainsInput = 1;
			}
			if (input == "2") {
				mainsInput = 2;
				return 0; //just testing first option at the moment
			}

			while (mainsInput == 1) {
				cout << "In the menu, there are numbers listed next to all the dishes. \n";
				cout << "Please enter the number of the dish you would like to add to your order: ";
				cin >> dishNum;
				inputError = displayInputError(dishNum, mainsMenu.getDishCount());
				while(inputError == true) {
					cin >> dishNum;
					inputError = displayInputError(dishNum, mainsMenu.getDishCount());
				}
				//asking whether they would like entree or main:
				size = "0";
				cout << "Please enter the number corresponding to the size you would like to order:\n";
				cout << "(1) Main\n" << "(2) Entree\n";
				cin >> size;
	
				while (size[0] - '0' < 1 || size[0] - '0' > 2) {
					cout << "That is not a valid number! Please enter either 1 or 2: ";
					cin >> size;
				} 

				dishIndex = (dishNum[0] - '0') - 1; //since indexing starts from 0. Also converting from string to int
				addedMains = mainsMenu.getMenuItem(dishIndex);
				addMains(orderArray, &currentDishes, addedMains, &totalCost, size[0], dishSizes);

				//prompt for next action:
				cout << "What would you like to do next?\n";
				cout << "Please enter a number: \n";
				cout << "(1) Add dish to order\n";
				cout << "(2) Look at a different menu\n";
				cout << "Type 'quit' at any time to exit the program\n";
				cin >> input;
				maxNumOptions = 2;
				inputError = displayInputError(input, maxNumOptions);

				while ( inputError == true) {
					cin >> input;
					inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
				}

				mainsInput = 0;
				if (input == "1") {
					mainsInput = 1;
				}
				if (input == "2") {
					mainsInput = 2;
				}
			}
		}

		while (menuInput == 2) {
			//looping for second option
			return 0; //just testing first option at the moment
			//prompt again, using input variable
		}

		while (menuInput == 3) {
			//looping for third option
			return 0; //just testing first option at the moment
			//prompt again, using input variable
		}

		// ....


	}

	//displayOptions(); //calling this jsut shows the user what menus are available
	
	delete[] orderArray;
	delete[] dishSizes;
	//delete any other memory allocated by new
	return 0;
}
