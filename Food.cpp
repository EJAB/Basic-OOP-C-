#include "Food.h"
#include <string>
#include <iostream>

using namespace std;

// 2. Over loading using constructors
Food::Food(): name("Not defined"), amount(), carbs_in_grams(), protein_in_grams(), fat_in_grams(){}

Food::Food(int anAmount): name("Not defined"), amount(anAmount), carbs_in_grams(), protein_in_grams(), fat_in_grams(){}

Food::Food(string aName, int anAmount):name(aName), amount(anAmount), carbs_in_grams(), protein_in_grams(), fat_in_grams(){}

Food::Food(int carbs_in_grams, int protein_in_grams, int fat_in_grams):name("Not defined"), amount(), carbs_in_grams(carbs_in_grams), protein_in_grams(protein_in_grams), fat_in_grams(fat_in_grams){}

Food::Food(string name, int amount, int carbs_in_grams, int protein_in_grams, int fat_in_grams):name(name), amount(amount), carbs_in_grams(carbs_in_grams), protein_in_grams(protein_in_grams), fat_in_grams(fat_in_grams){}

// 3. Over riding of a method
//This display method is overridden by Calories display() and Dessert display() which are both child classes
string Food::display(){
	string r = "Food type: " + name + " and amount: " + to_string(amount) +
			" contains the following: \ncarbohydrates in grams: " + to_string(carbs_in_grams) + " \nprotein in grams: " + to_string(protein_in_grams) +
			" \nfat in grams: " + to_string(fat_in_grams);
	cout << r << endl;
	return r;
}

// 9. A working destructor with some basic functionality
Food::~Food(){cout << "Food object is being destroyed" << endl;}

// 10. Correct use of three over-loaded operators
Food Food::operator + (Food f){
	return Food(name, amount + f.amount, carbs_in_grams + f.carbs_in_grams, protein_in_grams + f.protein_in_grams, fat_in_grams + f.fat_in_grams);
}

Food Food::operator = (Food y){
	return Food(amount = y.amount);
}

bool Food::operator == (const Food f){
	if((f.amount == amount) && (f.name == name) && (f.carbs_in_grams == carbs_in_grams) && (f.protein_in_grams == protein_in_grams) && (f.fat_in_grams == fat_in_grams)){
		return true;
	}
	else return false;
}

// 12. Static cast
void Food::staticCast(){
	cout << "amount variable was a " << typeid(amount).name() << endl;
	float f = static_cast<float>(amount);
	cout << " and after cast it is " <<typeid(f).name() << endl;
}

// 12. Const cast
void Food::constCast(int& x){
	++x;
}

//13. Dynamic binding non-virtual parent method
string Food::dynBind(){
	string s = "Food Object";
	cout << s << endl;
	return s;
}

// 17. To demonstrate passing an object to a method by constant reference
void Food::carbAddition(const Food &source){
	int newCarbs = (carbs_in_grams + source.carbs_in_grams);
	cout << "Original: " << carbs_in_grams << " plus object passed by constant reference carbohydrate value: " << source.carbs_in_grams << "\nCalculator result: " << newCarbs << endl;
}

//To demonstrate vector and algorithm points 19 and 20
int Food::printAmount(){
	cout << amount << endl;
	return amount;
}
