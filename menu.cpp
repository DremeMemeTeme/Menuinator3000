#include <string>
#include "menu.h"
#include "dish.h"

using namespace std;

menu::menu(){
	 dish ** dishArray;
	 menuName = "Generic Menu Name";
	 maxItems = 10;
	 dishType = "Generic Food Item"; 
	 dishCount = 0;

} 

menu::menu(std::string menuTitle, std::string itemType, int MAXitems)
{
	dish ** dishArray = new dish * [MAXitems]; //array of dish pointers size of MAXitems
	menuName = menuTitle;
	maxItems = MAXitems; 
	dishType = itemType;
	dishCount = 0;

}

void menu::addDish(dish * foodtoAdd){
	if(dishCount < maxItems){
		dishArray[dishCount] = foodtoAdd;
		dishCount++;
	}
}

string menu::getDishName(int i){
	return dishArray[i]->getName();
}

string menu::getMenuName() {
	return menuName;
}

int menu::getMax(){
	return maxItems;
}

int menu::getDishCount() {
	return dishCount;
}

dish * menu::getMenuItem(int i) { //returns a pointer to a food item in the menu
	return dishArray[i];
}

void menu::setName(string newName){
	menuName = newName;
}

menu::~menu(){
	delete[] dishArray;
}
