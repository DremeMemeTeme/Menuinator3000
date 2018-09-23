#ifndef MAINS_H
#define MAINS_H

#include "dish.h"
#include <string>

class mains: public dish { //inherits from dish class
	static int numMains; //counter for how many main objects have been created
	double entreePrice;
	bool spiciness;

public:
	mains(); //default constructor - delete if not used
	mains(std::string dishName, double regPrice, std::string allergyInfo, double MentreePrice, bool spicy);

	//getters
	void displayMains();
	bool isSpicy();
	//double getPrice(); 
	double getEntreePrice();

	//default deconstructor
	~mains();
};

#endif