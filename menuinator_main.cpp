#include <string>
#include <iostream>

#include <string.h>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"
#include "menu.h"
#include "mainsmenu.h"
#include "dessertsmenu.h"
#include "drinkmenu.h"

using namespace std;

extern void addMains(dish ** order, int * currentDishes, mains * addedMains, double * totalCost, string size, int * dishSizes);
extern void cancelDish(dish ** order, int dishIndex, int * currentDishes, double * totalCost, int * dishSizes);
extern int findDishInOrder(string inputtedName, dish ** orderArray, int currentDishes);
extern void displayCurrentOrder(dish ** orderArray, int currentDishes, double totalCost, int * dishSizes);
extern void addDessert(dish ** order, int * currentDishes, dessert * addedDessert, double * totalCost, int * dishSizes);
extern void addDrink(dish ** order, int * currentDishes, drink * addedDrink, double * totalCost, string size, int * dishSizes);
extern bool displayInputError(string input, int maxNumOptions);
//extern displayMenu functions here
extern void displayOptions();
extern bool quitCondition(string input);


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
	

	//creating order array
	int maxDishes = 15; //max dishes that customer can order
	dish ** orderArray = new dish * [maxDishes];
	int * dishSizes = new int[maxDishes]; //array for storing the sizes of dishes ordered

	int currentDishes = 0; //for counting how many dishes currently in order
	int * currentDishesPtr = &currentDishes; //pointer to current dishes variable
	double totalCost = 0.0; //initializing total cost variable

	string input = "0"; //initializing customer input variable

	string exitInput = "quit";
	int exitCondition = 1;

	//declaring all variables used within the following while loops here:
	string dishNum; //initializing "add dish" number variable - declared as a string to cope with possible char input
	int menuInput; //variable for deciding which menu to display - so that options don't get confused by only using "input"
	int mainsInput; 
	int dishIndex; //variable for the index of the dish to be added in the menu array
	mains * addedMains; //mains dish that user wants to add to order
	string size; //stores the size of the dish (eg entree vs mains)
	drink * addedDrink; //drink that user wants to add to order

	cout << "Welcome to the Menuinator 3000!\n";

	while (exitCondition != 0) { //may or may not work having this loop
		/*
		cout << "Welcome to the Menuinator 3000! \nWhich menu would you like to look at today?\n";
		cout << "(1) Mains Menu\n";
		cout << "(2) Drinks Menu\n";
		cout << "(3) Dessert Menu\n";
		cout << "Please enter the number of the menu you would like to look at: ";
		*/

		displayOptions(); //calling this shows user what menus are available
		cout << "Type 'quit' at any time to exit the program\n";
		cin >> input;
		if (quitCondition(input) == true) {
			//display goodbye message function? or include this in quitCondition function?
			return 0;
		}

		int maxNumOptions = 3;
		bool inputError = displayInputError(input, maxNumOptions); 
		while (inputError == true) {
			cin >> input;
			if (quitCondition(input) == true) {
				//display goodbye message function? or include this in quitCondition function?
				return 0;
			}
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

		//Bianca doing drink option, Vanessa doing dessert option

		while (menuInput == 1) {
			//Display mains menu function
			cout << "\nWhat would you like to do next?\n";
			cout << "Please enter a number: \n";
			cout << "(1) Add dish to order\n";
			cout << "(2) Look at a different menu\n";
			cout << "(3) Finalise order\n";
			cout << "(4) Cancel dish from order\n";
			cout << "Type 'quit' at any time to exit the program\n";
			cin >> input;
			if (quitCondition(input) == true) {
				//display goodbye message function? or include this in quitCondition function?
				return 0;
			}
			maxNumOptions = 4;
			inputError = displayInputError(input, maxNumOptions);

			while ( inputError == true) {
				cin >> input;
				if (quitCondition(input) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
				inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
			}
			mainsInput = 0;
			if (input == "1") {
				mainsInput = 1;
			}
			if (input == "2") {
				mainsInput = 2;
				menuInput = 0; //hopefully will exit the loop?
				//return 0; //just testing first option at the moment
			}
			if (input == "3") {
				mainsInput = 3;
				if (currentDishes == 0) {
					cout << "\nPlease add some items to your order first!\n";
					menuInput = 0; //go back to start
				} else {
					cout << "\nYour current order is: \n";
					displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);
					cout << "\nAre you sure you would like to finalise your order?\n";
					cout << "(y) Yes\n";
					cout << "(n) No\n";
					cin >> input;
					if (quitCondition(input) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}

					while (input != "Y" && input != "y" && input != "N" && input != "n") {
						cout << "Invalid input! Please enter either 'y' or 'n': ";
						cin >> input;
						if (quitCondition(input) == true) {
							//display goodbye message function? or include this in quitCondition function?
							return 0;
						}
					}

					if (input == "y" || input == "Y") {
						cout << "Thank you for using the Menu-inator 3000!\n";
						cout << "Your order has been processed. Please collect your order and pay in-store.\n";
						return 0;
					}

					if (input == "n" || input == "N") {
						menuInput = 0; //return to start
					}
				}
			}
			if (input == "4") {
				mainsInput = 4;
				cout << "Please enter the name of the dish you want to remove from your order: \n";
				cout << "(Type 'cancel' to go back to the menu selection screen)\n";
				cin.ignore(100, '\n'); //ignores newline character for cin input
				getline(cin, input);
				if (quitCondition(input) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}

				if (strcasecmp(input.c_str(), "cancel") == 0) {
					menuInput = 0; //return to start
				}

				dishIndex = findDishInOrder(input, orderArray, currentDishes);
				while (dishIndex == -1 && menuInput != 0) {
					cout << "\nDish not found! Please enter the name again: \n";
					cout << "(Type 'cancel' to go back to the menu selection screen)\n";
					cin.ignore(100, '\n'); 
					getline(cin, input);
					if (quitCondition(input) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}

					if (strcasecmp(input.c_str(), "cancel") == 0) {
						menuInput = 0; //exit while loop
					}

					dishIndex = findDishInOrder(input, orderArray, currentDishes);
				}
				
				if (menuInput != 0) { //so that doesn't enter this loop if user has typed "cancel"
					cancelDish(orderArray, dishIndex, currentDishesPtr, &totalCost, dishSizes);
					//displays "your order is now..." message in cancelDish function
					displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);
				}
				
			}

			while (mainsInput == 1) {
				cout << "\nIn the menu, there are numbers listed next to all the dishes. \n";
				cout << "Please enter the number of the dish you would like to add to your order: ";
				cin >> dishNum;
				if (quitCondition(dishNum) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
				inputError = displayInputError(dishNum, mainsMenu.getDishCount());
				while(inputError == true) {
					cin >> dishNum;
					if (quitCondition(dishNum) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}
					inputError = displayInputError(dishNum, mainsMenu.getDishCount());
				}
				//asking whether they would like entree or main:
				size = "0";
				cout << "Please enter the number corresponding to the size you would like to order:\n";
				cout << "(1) Main\n" << "(2) Entree\n";
				cin >> size;
				if (quitCondition(size) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
	
				while (size[0] - '0' < 1 || size[0] - '0' > 2) {
					cout << "That is not a valid number! Please enter either 1 or 2: ";
					cin >> size;
					if (quitCondition(size) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}
				} 

				dishIndex = (dishNum[0] - '0') - 1; //since indexing starts from 0. Also converting from string to int
				addedMains = mainsMenu.getMainsMenuItem(dishIndex);
				addMains(orderArray, currentDishesPtr, addedMains, &totalCost, size, dishSizes);

				//prompt for next action:
				cout << "\nWhat would you like to do next?\n";
				cout << "Please enter a number: \n";
				cout << "(1) Add dish to order\n";
				cout << "(2) Look at a different menu\n";
				cout << "(3) Finalise order\n";
				cout << "(4) Cancel dish from order\n";
				cout << "Type 'quit' at any time to exit the program\n";
				cin >> input;
				if (quitCondition(input) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
				maxNumOptions = 4;
				inputError = displayInputError(input, maxNumOptions);

				while ( inputError == true) {
					cin >> input;
					if (quitCondition(input) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}
					inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
				}

				//mainsInput = 0;
				if (input == "1") {
					mainsInput = 1;    //acutally might not need this loop
				}
				if (input == "2") {
					mainsInput = 2;
					menuInput = 0; //hopefully will exit the loop - works!
				}
				if (input == "3") {
					mainsInput = 3;
					if (currentDishes == 0) {
						cout << "\nPlease add some items to your order first!\n";
						menuInput = 0; //go back to start
					} else {
						cout << "\nYour current order is: \n";

						displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);
						cout << "\nAre you sure you would like to finalise your order?\n";
						cout << "(y) Yes\n";
						cout << "(n) No\n";
						cin >> input;
						if (quitCondition(input) == true) {
							//display goodbye message function? or include this in quitCondition function?
							return 0;
						}

						while (input != "Y" && input != "y" && input != "N" && input != "n") {
							cout << "Invalid input! Please enter either 'y' or 'n': ";
							cin >> input;
							if (quitCondition(input) == true) {
								//display goodbye message function? or include this in quitCondition function?
								return 0;
							}
						}

						if (input == "y" || input == "Y") {
							cout << "Thank you for using the Menu-inator 3000!\n";
							cout << "Your order has been processed. Please collect your order and pay in-store.\n";
							return 0;
						}

						if (input == "n" || input == "N") {
							menuInput = 0; //return to start
						}
					}
				}
				if (input == "4") {
					mainsInput = 4;
						while (mainsInput == 4) {
						cout << "Please enter the name of the dish you want to remove from your order: \n";
						cout << "(Type 'cancel' to go back to the menu selection screen)\n";
						cin.ignore(100, '\n');
						getline(cin, input);
						if (quitCondition(input) == true) {
							//display goodbye message function? or include this in quitCondition function?
							return 0;
						}

						if (strcasecmp(input.c_str(), "cancel") == 0) {
							menuInput = 0; //return to start
						}

						dishIndex = findDishInOrder(input, orderArray, currentDishes);
						while (dishIndex == -1 && menuInput != 0) {
							cout << "\nDish not found! Please enter the name again: \n";
							cout << "(Type 'cancel' to go back to the menu selection screen)\n";
							cin.ignore(100, '\n');
							getline(cin, input);
							if (quitCondition(input) == true) {
								//display goodbye message function? or include this in quitCondition function?
								return 0;
							}

							if (strcasecmp(input.c_str(), "cancel") == 0) {
								menuInput = 0; //exit while loop
							}

							dishIndex = findDishInOrder(input, orderArray, currentDishes);
						}
				
						if (menuInput != 0) { //so that doesn't enter this loop if user has typed "cancel"
							cancelDish(orderArray, dishIndex, currentDishesPtr, &totalCost, dishSizes);
							//displays "your order is now..." message in cancelDish function
							displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);

							//prompting for next input
							cout << "\nWhat would you like to do next?\n";
							cout << "Please enter a number: \n";
							cout << "(1) Add dish to order\n";
							cout << "(2) Look at a different menu\n";
							cout << "(3) Finalise order\n";
							cout << "(4) Cancel dish from order\n";
							cout << "Type 'quit' at any time to exit the program\n";
							cin >> input;
							if (quitCondition(input) == true) {
								//display goodbye message function? or include this in quitCondition function?
								return 0;
							}
							maxNumOptions = 4;
							inputError = displayInputError(input, maxNumOptions);

							while ( inputError == true) {
								cin >> input;
								if (quitCondition(input) == true) {
									//display goodbye message function? or include this in quitCondition function?
									return 0;
								}
								inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
							}
							//mainsInput = 0;
							if (input == "1") {
								mainsInput = 1;    //acutally might not need this loop
							}
							if (input == "2") {
								mainsInput = 2;
								menuInput = 0; //hopefully will exit the loop - works!
							}
							if (input == "3") {
								mainsInput = 3;
								if (currentDishes == 0) {
									cout << "\nPlease add some items to your order first!\n";
									menuInput = 0; //go back to start
								} else {
									cout << "\nYour current order is: \n";

									displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);
									cout << "\nAre you sure you would like to finalise your order?\n";
									cout << "(y) Yes\n";
									cout << "(n) No\n";
									cin >> input;
									if (quitCondition(input) == true) {
										//display goodbye message function? or include this in quitCondition function?
										return 0;
									}

									while (input != "Y" && input != "y" && input != "N" && input != "n") {
										cout << "Invalid input! Please enter either 'y' or 'n': ";
										cin >> input;
										if (quitCondition(input) == true) {
											//display goodbye message function? or include this in quitCondition function?
											return 0;
										}
									}

									if (input == "y" || input == "Y") {
										cout << "Thank you for using the Menu-inator 3000!\n";
										cout << "Your order has been processed. Please collect your order and pay in-store.\n";
										return 0;
									}

									if (input == "n" || input == "N") {
										menuInput = 0; //return to start
									}
								}

								if (input == "4") {
									mainsInput = 4; //should go back through the loop
								}
							}								
						}
					}
				}
			}
		}
		while (menuInput == 2) { //drinks menu
			//display drinks menu function

			cout << "\nIn the menu, there are numbers listed next to all the items. \n";
				cout << "Please enter the number of the item you would like to add to your order: ";
				cin >> dishNum;
				if (quitCondition(dishNum) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
				inputError = displayInputError(dishNum, drinkMenu.getDishCount());
				while(inputError == true) {
					cin >> dishNum;
					if (quitCondition(dishNum) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}
					inputError = displayInputError(dishNum, drinkMenu.getDishCount());
				}
				//asking whether they would like entree or main:
				size = "0";
				cout << "Please enter the number corresponding to the size you would like to order:\n";
				cout << "(1) Bottle\n" << "(2) Glass\n";
				cin >> size;
				if (quitCondition(size) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
	
				while (size[0] - '0' < 1 || size[0] - '0' > 2) {
					cout << "That is not a valid number! Please enter either 1 or 2: ";
					cin >> size;
					if (quitCondition(size) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}
				} 

				dishIndex = (dishNum[0] - '0') - 1; //since indexing starts from 0. Also converting from string to int
				addedDrink = drinkMenu.getDrinkMenuItem(dishIndex);
				addDrink(orderArray, currentDishesPtr, addedDrink, &totalCost, size, dishSizes);

				//prompt for next action:
				cout << "\nWhat would you like to do next?\n";
				cout << "Please enter a number: \n";
				cout << "(1) Add item to order\n";
				cout << "(2) Look at a different menu\n";
				cout << "(3) Finalise order\n";
				cout << "(4) Cancel item from order\n";
				cout << "Type 'quit' at any time to exit the program\n";
				cin >> input;
				if (quitCondition(input) == true) {
					//display goodbye message function? or include this in quitCondition function?
					return 0;
				}
				maxNumOptions = 4;
				inputError = displayInputError(input, maxNumOptions);

				while ( inputError == true) {
					cin >> input;
					if (quitCondition(input) == true) {
						//display goodbye message function? or include this in quitCondition function?
						return 0;
					}
					inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
				}

				//mainsInput = 0;
				if (input == "1") {
					mainsInput = 1;    //acutally might not need this loop
				}
				if (input == "2") {
					mainsInput = 2;
					menuInput = 0; //hopefully will exit the loop - works!
				}
				if (input == "3") {
					mainsInput = 3;
					if (currentDishes == 0) {
						cout << "\nPlease add some items to your order first!\n";
						menuInput = 0; //go back to start
					} else {
						cout << "\nYour current order is: \n";

						displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);
						cout << "\nAre you sure you would like to finalise your order?\n";
						cout << "(y) Yes\n";
						cout << "(n) No\n";
						cin >> input;
						if (quitCondition(input) == true) {
							//display goodbye message function? or include this in quitCondition function?
							return 0;
						}

						while (input != "Y" && input != "y" && input != "N" && input != "n") {
							cout << "Invalid input! Please enter either 'y' or 'n': ";
							cin >> input;
							if (quitCondition(input) == true) {
								//display goodbye message function? or include this in quitCondition function?
								return 0;
							}
						}

						if (input == "y" || input == "Y") {
							cout << "Thank you for using the Menu-inator 3000!\n";
							cout << "Your order has been processed. Please collect your order and pay in-store.\n";
							return 0;
						}

						if (input == "n" || input == "N") {
							menuInput = 0; //return to start
						}
					}
				}
				if (input == "4") {
					mainsInput = 4;
						while (mainsInput == 4) {
						cout << "Please enter the name of the dish you want to remove from your order: \n";
						cout << "(Type 'cancel' to go back to the menu selection screen)\n";
						cin.ignore(100, '\n');
						getline(cin, input);
						if (quitCondition(input) == true) {
							//display goodbye message function? or include this in quitCondition function?
							return 0;
						}

						if (strcasecmp(input.c_str(), "cancel") == 0) {
							menuInput = 0; //return to start
						}

						dishIndex = findDishInOrder(input, orderArray, currentDishes);
						while (dishIndex == -1 && menuInput != 0) {
							cout << "\nDish not found! Please enter the name again: \n";
							cout << "(Type 'cancel' to go back to the menu selection screen)\n";
							cin.ignore(100, '\n');
							getline(cin, input);
							if (quitCondition(input) == true) {
								//display goodbye message function? or include this in quitCondition function?
								return 0;
							}

							if (strcasecmp(input.c_str(), "cancel") == 0) {
								menuInput = 0; //exit while loop
							}

							dishIndex = findDishInOrder(input, orderArray, currentDishes);
						}
				
						if (menuInput != 0) { //so that doesn't enter this loop if user has typed "cancel"
							//cout << "Entered cancel loop\n";
							cancelDish(orderArray, dishIndex, currentDishesPtr, &totalCost, dishSizes);
							//displays "your order is now..." message in cancelDish function
							displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);

							//prompting for next input
							cout << "\nWhat would you like to do next?\n";
							cout << "Please enter a number: \n";
							cout << "(1) Add dish to order\n";
							cout << "(2) Look at a different menu\n";
							cout << "(3) Finalise order\n";
							cout << "(4) Cancel dish from order\n";
							cout << "Type 'quit' at any time to exit the program\n";
							cin >> input;
							if (quitCondition(input) == true) {
								//display goodbye message function? or include this in quitCondition function?
								return 0;
							}
							maxNumOptions = 4;
							inputError = displayInputError(input, maxNumOptions);

							while ( inputError == true) {
								cin >> input;
								if (quitCondition(input) == true) {
									//display goodbye message function? or include this in quitCondition function?
									return 0;
								}
								inputError = displayInputError(input, maxNumOptions); //continually prompts for input as long as input is invalid
							}
							//mainsInput = 0;
							if (input == "1") {
								mainsInput = 1;    //acutally might not need this loop
							}
							if (input == "2") {
								mainsInput = 2;
								menuInput = 0; //hopefully will exit the loop - works!
							}
							if (input == "3") {
								mainsInput = 3;
								if (currentDishes == 0) {
									cout << "\nPlease add some items to your order first!\n";
									menuInput = 0; //go back to start
								} else {
									cout << "\nYour current order is: \n";

									displayCurrentOrder(orderArray, currentDishes, totalCost, dishSizes);
									cout << "\nAre you sure you would like to finalise your order?\n";
									cout << "(y) Yes\n";
									cout << "(n) No\n";
									cin >> input;
									if (quitCondition(input) == true) {
										//display goodbye message function? or include this in quitCondition function?
										return 0;
									}

									while (input != "Y" && input != "y" && input != "N" && input != "n") {
										cout << "Invalid input! Please enter either 'y' or 'n': ";
										cin >> input;
										if (quitCondition(input) == true) {
											//display goodbye message function? or include this in quitCondition function?
											return 0;
										}
									}

									if (input == "y" || input == "Y") {
										cout << "Thank you for using the Menu-inator 3000!\n";
										cout << "Your order has been processed. Please collect your order and pay in-store.\n";
										return 0;
									}

									if (input == "n" || input == "N") {
										menuInput = 0; //return to start
									}
								}

								if (input == "4") {
									mainsInput = 4; //should go back through the loop
								}
							}								
						}
					}
				}
			}
		}

		while (menuInput == 3) {
			//looping for third option
			return 0; //just testing first option at the moment
			//prompt again, using input variable
		}

		// ....


	//}

	//displayOptions(); //calling this jsut shows the user what menus are available
	
	delete[] orderArray;
	delete[] dishSizes;
	//delete any other memory allocated by new
	return 0;
}