#ifndef MAINS_H
#define MAINS_H

#include "dish.h"
#include <string>

class mains: public dish { //inherits from dish class
	static int numMains; //counter for how many main objects have been created
	double entreePrice;
	bool spiciness;
	std::string allergens;
	std::string type; //used for differentiating between subclasses
	//std::string size; - might not need this

public:
	mains(); //default constructor 
	mains(std::string dishName, double regPrice, std::string allergyInfo, double MentreePrice, bool spicy);

	//getters
	bool isSpicy();
	std::string getInfo(); //returns allergen information
	double getEntreePrice();
	std:: string getType();
	//std::string getSize(); //returns whether entree or main

	//default deconstructor
	~mains();
};

#endif