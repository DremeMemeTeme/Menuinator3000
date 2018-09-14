#ifdef TIGER_H
#define TIGER_H

#include <string>

class Tiger : public Animal {
	int prey_killed;

public:

	//constuctor
	Tiger();
	Tiger(std::string name, int id);

	void hunt();

};
#endif



/*--------------------------------------------------
 »» NOTES ««

if i tiger had a private function, the only 
thing that can call it is the tiger function

generally want things to be private unless 
you will make changes to it or interact with it



*/