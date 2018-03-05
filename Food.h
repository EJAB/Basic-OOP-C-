#ifndef FOOD_H_
#define FOOD_H_

#include <iostream>
#include <string>

using std::string;

class Food {
	// 1. Correct use of all access specifiers
protected:
	string name;
	int amount;
	int carbs_in_grams;
	int protein_in_grams;
	int fat_in_grams;

public:
	// 2. Overloading using constructors
	Food();
	Food(int amount);
	Food(string name, int amount);
	Food(int carbs_in_grams, int protein_in_grams, int fat_in_grams);
	Food(string name, int amount, int carbs_in_grams, int protein_in_grams, int fat_in_grams);

	// 6. Example use of a friend function that receives an object of a class - Takes in a Food object
	friend void friend_function(Food &);

	// 9. Destructor
	virtual ~Food();

	// 10. Correct use of three over-loaded operators
	Food operator + (Food);
	Food operator = (Food);
	bool operator == (Food);

	// 12. C++ Explicit casts
	virtual void staticCast();
	virtual void constCast(int&);

	// 13. To demonstrate dynamic binding on virtual method, overridden by child (Dessert or Calories) object method
	virtual string display();

	// 13. To demonstrate dynamic binding on non-virtual method
	string dynBind();

	// 17. To demonstrate passing an object to a method by constant reference
	virtual void carbAddition(const Food &);

	// Used for point 19 and 20 to sort based on size
	virtual int printAmount();
	bool operator < (const Food& f) const {return (amount < f.amount ? true : false ); }
};

#endif /* FOOD_H_ */
