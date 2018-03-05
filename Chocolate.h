#ifndef CHOCOLATE_H_
#define CHOCOLATE_H_

#include <iostream>
#include <string>

using std::string;

// 7. Abstract Class
class Chocolate {
protected:
	string brand;
	int block;

public:
	Chocolate(string brand, int block);
	Chocolate(string brand);
	virtual ~Chocolate();

	virtual string display();

	// 7. Abstract classes with a method that is required in all derived classes (Dessert class)
	virtual string sugar_content(int) = 0;
};


#endif /* CHOCOLATE_H_ */
