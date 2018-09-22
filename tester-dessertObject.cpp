#include <iostream>
#include "dish.h"
#include "dessert.h"

using namespace std;

int main() {
	dessert chocolateMousse = dessert("Chocolate Mousse", 8.90, "dairy, eggs", "sweet");

	cout << "Dish name: " << chocolateMousse.getName() << "\n";
	cout << "Price: $" << chocolateMousse.getPrice() << "\n";
	cout << "It is " << chocolateMousse.howSweet() << "\n";
	cout << "*Contains " << chocolateMousse.getAllergens() << "\n";

	return 0;
}