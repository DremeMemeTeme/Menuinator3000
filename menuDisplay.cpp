
// a sad attempt at displaying menu items

#include <iostream>
using namespace std;

int main ()
{

  //string menuItem[] = {"burger", "fries", "salad"};
  string menuItem;

  //double price[] = {50.45, 4.50, 18.20};
  double price = 34.60;


  //have something like price * quantity somewhere?
  //either as a function or written plainly price*quantity 
  //witht the cout lines



  cout << "What would you like to have? ";
  cin >> menuItem; 

/*Note with this if the name of the food typed has more than
one word then it only recognizes the first word*/


if(menuItem == "chips" || menuItem == "Chips"){
	price = 4.50;
}

if(menuItem == "water" || menuItem == "Water"){
	price = 6.54;
}

  cout << "The item you chose is " << menuItem;
  cout << " and it costs " << price<< ".\n";
  return 0;

}