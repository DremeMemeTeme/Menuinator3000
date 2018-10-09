#include <string>
#include <iostream>
#include <string.h>
#include "dish.h"
#include "mains.h"
#include "dessert.h"
#include "drink.h"
//#include "menu.h"

using namespace std;

//testing a possible generic addDish function - would require more object properties to be added

void addDish(dish ** orderArray, int * currentDishes, double * totalCost, dish * addedDish) {
	switch addedDish->getType() {
		orderArray[*currentDishes] = addedDish; //these 2 lines true for all cases
		*currentDishes = *currentDishes + 1;
		case "mains" :
		int size = 0;
		cout << "Please enter the number corresponding to the size you would like to order:\n";
		cout << "(1) Main\n" << "(2) Entree\n";
		cin >> size;
		while (size < 1 || size > 2) {
			cout << "That is not a valid number! Please enter either 1 or 2: ";
			cin >> size;
		} else {
			switch size {
				case 1:
				addedDish->setSize("main");
				break;

				case 2:
				addedDish->setSize("entree");
				break;
			}
		}
		if (addedDish->getMainsSize() == "entree") { //will need a "setSize" function
			*totalCost = *totalCost + addedDish->getEntreePrice();
		} else {
			*totalCost = *totalCost + addedDish->getPrice();
		}
		break;

		case "dessert" :
		*totalCost = *totalCost + addedDish->getPrice();
		break;

		case "drink" :
		int size = 0;
		cout << "Please enter the number corresponding to the size you would like to order:\n";
		cout << "(1) Glass\n" << "(2) Bottle\n";
		cin >> size;
		while (size < 1 || size > 2) {
			cout << "That is not a valid number! Please enter either 1 or 2: ";
			cin >> size;
		} else {
			switch size {
				case 1:
				addedDish->setSize("glass");
				break;

				case 2:
				addedDish->setSize("bottle");
				break;
			}
		}
		if (addedDish->getDrinkSize() == "glass") { //will need a "setSize" function
			*totalCost = *totalCost + addedDish->getPrice();
		} else {
			*totalCost = *totalCost + addedDish->getBottlePrice();
		}
		break;
	}

	//successfully added message?
}