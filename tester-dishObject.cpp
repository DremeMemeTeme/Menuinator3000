#include <iostream>
#include "dish.h"
//#include <string>?

using namespace std;

int main() {
	//testing default constructor
	dish spagBol;
	cout << "Dish name: " << spagBol.getName() << "\n";
	cout << "Dish price: " << spagBol.getPrice() << "\n";
	cout << "Allergen info: " << spagBol.getAllergens() << "\n";

	dish sandwich = dish("Sandwich", 6.50, "Gluten");
	cout << "Dish name: " << sandwich.getName() << "\n";
	cout << "Dish price: $" << sandwich.getPrice() << "\n";
	cout << "Allergen info: " << sandwich.getAllergens() << "\n";

	return 0;
}