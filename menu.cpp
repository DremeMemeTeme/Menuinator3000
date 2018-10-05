#include <string>
#include "menu.h"

//#include "dish.h"
//#include "mains.h"
//#include "drinks.h"
//#include "desserts.h"

using namespace std;

menu::menu(){
	 dish * dishArray;
	 menuName = "Generic Menu Name";
	 maxItems = 10;
	 dishType = "Generic Food Item"; 

} 

menu::menu(std::string menuTitle, std::string itemType, int numOfItems)
{
	dish * dishArray;
	menuName = menuTitle;
	maxItems = 
	dishType = itemType;

}

void menu::addDish(dish foodtoAdd){
	if(dishCount < maxItems){
		dishCollection[dishCount] = foodtoAdd;
		dishCount++;
	}
}

string menu::dishName(){

}

int menu::getMax(){
	return maxItems;
}

void setName(string newName){
	menuName = newName;
}

menu::~menu(){
}
