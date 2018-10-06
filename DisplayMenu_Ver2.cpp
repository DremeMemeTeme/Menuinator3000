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


	//VARIABLES FOR USER INPUT
	string menuChoice;  //if user has to input a string/name of food/menu
	int choiceOption;   //if user has to input which option they would like to do next


	cout <<"What would you like to look at?" << '\n';
	cout <<"(Please enter the number of the menu you would like to look at)" << '\n';
	cout <<"(1) Mains Menu" << '\n';
	cout <<"(2) Drinks Menu" << '\n';
	cout <<"(3) Desserts Menu" << '\n';


	//cin >> menuChoice;
	cin >> choiceOption;

	if(choiceOption == 1)
	{
		cout << "HERE IS OUR MAINS MENU:" << '\n';
		for(int i=0; i<mainsCount; i++)
		{
			cout << mainsMenu[i] << "....." << "$ " << mainsPrice[i] << '\n'; //in final program, insert "displayMainsMenu" function here
		}
	}

	if(choiceOption == 2)
	{
		cout << "HERE IS OUR DRINKS MENU:" << '\n';
		for(int i=0; i<drinksCount; i++)
		{
			cout << drinksMenu[i] << "....." << "$ " << drinksPrice[i] << '\n';
		}
	}

	if(choiceOption == 3)
	{
			cout << "HERE IS OUR DESSERT MENU:" << '\n';
			for(int i=0; i<dessertCount; i++)
			{
				cout << dessertMenu[i] << "....." << "$ " << dessertPrice[i] << '\n';
			}
	}


	else if(choiceOption > 3 || choiceOption < 1)
	{
		cout << "Please enter a valid number" << '\n';
	}

	return 0;
}

/*-------------------------------------

so the way this thing currently works is that
if you enter 1,2 or 3 it will show the menu you want

if you enter decimals like 1.2223 2.555 and all that 
it kinda works like a floor function where 1.6 = 1 and 
2.545 = 2  and all that... (not sure if this is what we want or not)

numbers that are grater than 3 and lower than one (including 
0 or negative numbers) will show the error message

*/








