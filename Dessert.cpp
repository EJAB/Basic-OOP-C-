#include <iostream>
#include <string>
#include "Chocolate.h"
#include "Food.h"
#include "Dessert.h"

using namespace std;

Dessert::Dessert(string aType, string aBrand, int anAmount):Food(anAmount), Chocolate(aBrand){
	type = aType;
	brand = aBrand;
	amount = anAmount;
	cout << "Dessert Child object being created from abstract class Chocolate" << endl;
}

// 8. Modified Copy constructor (Amount + 10000)
Dessert::Dessert(const Dessert &source):Food(amount), Chocolate(brand){
	type = source.type;
	brand = source.brand;
	amount = source.amount + 10000;
}

Dessert::~Dessert() {cout << "Dessert child object is  being destroyed" << endl;}

// 3. Over riding of a method - Overrides parent display() methods, from Food class and Chocolate class if one is declared
string Dessert::display(){
	string s = "Dessert type: " + type + " by: " + brand + " and amount: "+ to_string(amount);
	cout << s << endl;
	return s;
}

// 7. Abstract classes with a method that is required in all derived classes
string Dessert::sugar_content(int sugar){
	string s = "There is this much sugar in this " + type + ": " + to_string(sugar) + "grams";
	cout << s << endl;
	return s;
}
