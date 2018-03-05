#include "Calories.h"
#include "Food.h"
#include "Calculator.h"
using namespace std;

Calories::Calories():Food(), Calculator() {}

Calories::Calories(int carbs_in_grams, int protein_in_grams, int fat_in_grams):Food(carbs_in_grams, protein_in_grams, fat_in_grams), Calculator() {
	this->carbs_in_grams = carbs_in_grams;
	this->protein_in_grams = protein_in_grams;
	this->fat_in_grams = fat_in_grams;
}

Calories::~Calories() {
	cout << "Calories Object is being destroyed" << endl;
}

// 3. Over riding of a method - Overrides parent display() methods, from Food class and Calculator class
// 13. To demonstrate dynamic binding on virtual method, overridden by child (Dessert or Calories) object method
string Calories::display(){
	cout << "Calories from carbohydrates is: " << carbs_in_grams << endl;
	cout << "Calories from proteins is: " << protein_in_grams << endl;
	cout << "Calories from fats is: " << fat_in_grams << endl;
	Calories::total();
	return "Calories Calculated!";
}

//4. Example of multiple inheritance - Calculator method multiply() and Food parameters
//4 calories per gram - carbs
void Calories::carbs_calories(){carbs_in_grams = Calculator::multiply(carbs_in_grams, 4);}
//4 calories per gram - protein
void Calories::protein_calories(){protein_in_grams = Calculator::multiply(protein_in_grams, 4);}
//9 calories per gram - fat
void Calories::fat_calories(){fat_in_grams = Calculator::multiply(fat_in_grams, 9);}

void Calories::total(){
	int total = carbs_in_grams + protein_in_grams + fat_in_grams;
	cout << "Total calories: " << total << endl;
}

// 13. To demonstrate dynamic binding on non-virtual method, overridden by child (Dessert or Calories) object method
string Calories::dynBind(){
	string s = "Calories Object";
	cout << s << endl;
	return s;
}
