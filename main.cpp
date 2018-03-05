#include <iostream>
#include "Food.h"
#include "Chocolate.h"
#include "Dessert.h"
#include "Calculator.h"
#include "Calories.h"
#include <vector>
#include <algorithm>
using namespace std;

// 6. Example use of a friend function that receives an object of a class
void friend_function(Food &f){cout << "New amount of " << f.name << " after increment is: " << ++f.amount << ", so carbs, protein and fat in grams have increased to: "
	<< ++f.carbs_in_grams << ", " << ++f.protein_in_grams  << ", " << ++f.fat_in_grams << ", respectively." <<endl;}

//To demonstrate vector and algorithm points 19 and 20
void printAmount(Food a){
	a.printAmount();
}

//A straightforward class template that stores values
template<class T>
class Storage{
	T values[100];

public:
	T& operator [](int index){
		return values[index];
	}
};

int main(){
	// 1. Correct use of all access specifiers

	// 2. Over loading using methods or constructors
	cout << "\n2. Over loading of constructors\n----------------------------------------------------------------------" << endl;
	Food foods[3] = {
			Food(5),
			Food("Curry", 5,5,5,5),
			Food(3,4,5)
	};
	foods[0].display();
	foods[1].display();
	foods[2].display();
	Food *p = &foods[0];

	// 3. Over riding of a method
	cout << "\n3. Over Riding of a method\n----------------------------------------------------------------------" << endl;
	(++p)->display();
	Calories over_ride(3,4,5);
	over_ride.display();

	// 4. Example of multiple inheritance
	cout << "\n4. Multiple Inheritance\n----------------------------------------------------------------------" << endl;
	over_ride.carbs_calories();
	over_ride.protein_calories();
	over_ride.fat_calories();
	over_ride.display();

	// 5. Separate compilation with all classes in your assignment.

	// 6. Example use of a friend function that receives an object of a class
	cout << "\n6. Friend Function\n----------------------------------------------------------------------" << endl;
	friend_function(foods[1]);

	// 7. Abstract classes with a method that is required in all derived classes
	cout << "\n7. Abstract class\n----------------------------------------------------------------------" << endl;
	//Chocolate choc("Lindt", 10); // Can't make a Chocolate object because it is an Abstract class
	Dessert cake("Chocolate cake", "Dr. Oetker", 1);
	cake.sugar_content(123);

	// 8. A class with a modified copy constructor and demonstrate the effect of this on pass-by-value and pass-by-reference calls
	cout << "\n8. Copy Constructor\n----------------------------------------------------------------------" << endl;
	//Food copy(curry);
	Dessert dessie(cake);
	dessie.display();

	// 10. Correct use of three over-loaded operators (e.g. +, =, ==)
	cout << "\n10. Overloaded Operators\n----------------------------------------------------------------------" << endl;
	//+ operator
	Food op = foods[1] + foods[2];
	op.display();

	//= operator
	Food op2 = op;
	op2.display();

	//== operator
	Food op3(3,4,5);
	if (op3 == foods[2]){ cout << "op3 and food object #3 are equal" << endl;}
	else {cout << "op3 and food object #3 are not equal" << endl;}

	// 11. Operations on pointers to arrays of objects
	cout << "\n11. Pointers to arrays of objects\n----------------------------------------------------------------------" << endl;
	//Array of objects in Part 2
	p->display();

	// 12. Use of all four C++ style casts
	//Static Cast
	cout << "\n12. Casts\n----------------------------------------------------------------------" << endl;
	foods[0].staticCast();

	//Dynamic Cast
	Food *dynCast = new Calories(5,5,5);
	Calories *dynCast_child = dynamic_cast<Calories*>(dynCast);
	dynCast_child->display();

	//Const cast
	const int k = 6;
	p->constCast(*const_cast<int*>(&k));
	cout << "After const_cast, k value is: " << k << endl;

	//Reinterpret cast
	Food *l = new Food();
	long m = reinterpret_cast<long>(l);
	cout << typeid(l).name() << " with address: " << l << endl;
	cout << typeid(m).name() << " with address as long: " << m << endl;

	// 13. Use of dynamic binding with virtual and non-virtual methods
	cout << "\n13. Dynamic binding using virtual and non-virtual methods\n----------------------------------------------------------------------" << endl;
	Food *vir = new Food("q", 9, 9, 9, 9);
	Food *vir1 = new Calories(1,1,1);
	//virtual display parent method
	vir->display();
	//virtual display child method
	vir1->display();
	//non-virtual parent method
	vir->dynBind();
	//non-virtual child method - doesn't override parent, therefore displays parent statement
	vir1->dynBind();

	// 14. Correct use of new and delete for the allocation of an object, with operations on the object using pointers
	cout << "\n14. Dynamic Creation of objects using new and delete\n----------------------------------------------------------------------" << endl;
	Food *newFood = new Food("Chocolate cake", 1, 1, 1, 1);
	newFood->display();
	delete(newFood);

	// 15. Static states of a class and an example usage
	cout << "\n15. Static states of a class\n----------------------------------------------------------------------" << endl;
	Calculator static_state(5,10);
	static_state.multiply();
	static_state.display();

	// 16. Difference between a C++ class and a C++ struct
	cout << "\n16. Classes vs. Struct\n----------------------------------------------------------------------" << endl;
	/*
	 * Dessert.h is my struct data structure.
	 * Structs and Classes are very similar, the only difference is the member declaration
	 * In structs, members are public by default whereas in classes, members are private by default.
	 * In Dessert.h, public: doesn't need to be declared as members are public by default.
	 */
	cake.display();

	// 17. Passing an object to a method by constant reference
	cout << "\n17. Passing an object by Constant reference\n----------------------------------------------------------------------" << endl;
	foods[1].carbAddition(op3);

	// 18. Write a straightforward class template
	cout << "\n18. Straightforward class template\n----------------------------------------------------------------------" << endl;
	Storage<double> doubleArray;
	Storage<float> floatArray;

	for (int i=0; i<10; i++){
		doubleArray[i] = (double)i / 1.1234;
		floatArray[i] = (float)i / 2.1234 ;
	}

	for (int i=0; i<10; i++){
		cout << "doubleArray[" << i  << "] value = " << doubleArray[i] << " \tfloatArray["<< i << "] value = " << floatArray[i] << endl;
	}

	// 19. Use of the vector container to contain a number of objects of one of the classes
	cout << "\n19. Vector Container\n----------------------------------------------------------------------" << endl;
	vector<Food> F;  // declare a vector container of Food objects

	// 20. Use of an algorithm on the container
	cout << "\n20. Use of an algorithm (sort in this case) on the vector container\n----------------------------------------------------------------------" << endl;
	Food foodies[] = {Food(3), Food(5), Food(2), Food(1), Food(4), Food(3)};

	for(int i = 0; i < sizeof(foodies)/sizeof(foodies[0]); i++){
		F.push_back(foodies[i]);
	}

	sort(F.begin(), F.end());   // Algorithm
	cout << "Sorted food in alphabet order:" << endl;
	for_each(F.begin(), F.end(), printAmount);

	// 9. A working destructor with some basic functionality
	cout << "\nDestructors\n----------------------------------------------------------------------" << endl;
}
