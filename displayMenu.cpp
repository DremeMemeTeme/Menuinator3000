#include <iostream>
using namespace std;

/*
still needs to be modified such that the opjects are
included here rather that using the arrays made here.
*/

int main(){
	//string mainsMenu[] = {"Salad", "Chips", "Pasta", "Nachos"};
	//string drinksMenu[] = {"Coke", "Beer", "icedTea", "Juice"};
	//string dessertMenu[] = {"Cake", "IceCream", "FruitSalad", "Candy"};

	//double mainsPrice [] = {12.23, 4.98, 12.67, 5.67};
	//double drinksPrice[] = {5.78, 7.80, 3.55, 6.67};
	//double dessertPrice[] = {56.89, 34.67, 12.75, 17.89};

//----------------------------------------------------------

	string mainsMenu[] = {"Salad", "Chips", "Pasta", "Nachos", "GarlicBread"};
	string drinksMenu[] = {"Coke", "Beer", "icedTea"};
	string dessertMenu[] = {"Cake", "IceCream", "FruitSalad", "Candy", "Brownie"};

	double mainsPrice [] = {12.23, 4.98, 12.67, 5.67, 7.89};
	double drinksPrice[] = {5.78, 7.80, 3.55};
	double dessertPrice[] = {56.89, 34.67, 12.75, 17.89,43.87};

//----------------------------------------------------------

	int mainsCount = 5;  //number of items in the menu
	int drinksCount = 3; //number of items of drinks in drink menu
	int dessertCount = 5; //number of items in desserts menu

	string menuChoice;  //user input as a string

	cout <<"What would you like to look at?" << '\n';
	cin >> menuChoice;

	if(menuChoice == "Mains" ||menuChoice ==  "mains")
	{
		cout << "HERE IS OUR MAINS MENU:" << '\n';
		for(int i=0; i<mainsCount; i++)
		{
			cout << mainsMenu[i] << "....." << "$ " << mainsPrice[i] << '\n'; //in final program, insert "displayMainsMenu" function here
		}
	}

	if(menuChoice == "Drinks" ||menuChoice == "drinks")
	{
		cout << "HERE IS OUR DRINKS MENU:" << '\n';
		for(int i=0; i<drinksCount; i++)
		{
			cout << drinksMenu[i] << "....." << "$ " << drinksPrice[i] << '\n';
		}
	}

	if(menuChoice == "Dessert" ||menuChoice == "dessert"){
			cout << "HERE IS OUR DESSERT MENU:" << '\n';
			for(int i=0; i<dessertCount; i++)
			{
				cout << dessertMenu[i] << "....." << "$ " << dessertPrice[i] << '\n';
			}
	}


	else if(menuChoice != "Mains" && menuChoice != "mains" 
	   && menuChoice != "Dessert" && menuChoice != "dessert"
	   && menuChoice != "Drinks" && menuChoice != "drinks")
	{
		cout << "That is not an exsisting menu" << '\n';
	}

	//commnented out for now as this error message still
	//shows up at the bottom of the menu

	//my guess as to why this is because even if the user types
	//a valid menu name, it falls under the other || options too
	//so this error message will still show.

	return 0;
}