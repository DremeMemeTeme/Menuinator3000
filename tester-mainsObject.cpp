#include <iostream>
#include "mains.h"
#include "dish.h"

using namespace std;

int main() {
	mains butterChicken = mains("Butter Chicken", 18.90, "Nuts", 16.90, false);
	cout << "The dish " << butterChicken.getName() << " is $" << butterChicken.getPrice() << " for a main and $" << butterChicken.getEntreePrice() << " for an entree size.\n";
	cout << "It contains " << butterChicken.getAllergens() << ".\n";

	if (butterChicken.isSpicy() == true) {
		cout << "It is spicy.\n";
	} else {
		cout << "It is not spicy.\n";
	}

	return 0;
}