#ifndef DESSERT_H_
#define DESSERT_H_

#include <iostream>
#include <string>
#include "Food.h"
#include "Chocolate.h"

using std::string;

struct Dessert: public Food, public Chocolate {
	//Structs members are public by default
	Dessert(string brand, string type, int amount);
	virtual ~Dessert();

	// 3. Over riding of a method
	//This display method overrides parent display methods, from Food class and Chocolate class if one is declared
	string display();

	// 7. Abstract classes with a method that is required in all derived classes
	virtual string sugar_content(int);

	// 8. Modified Copy constructor
	Dessert(const Dessert &);

private:
	string type;
};

#endif /* DESSERT_H_ */
