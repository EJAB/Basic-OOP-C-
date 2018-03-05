#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

Calculator::Calculator(): x(), y(){plus_fifty();}
Calculator::Calculator(int x, int y): x(x), y(y){plus_fifty();}

Calculator::~Calculator(){cout << "Calculator object is being destroyed" << endl;}

int Calculator::add(int x, int y){
	cout << "Addition result of x: " << x << " and y: " << y << " is: " << x+y << endl;
	return x+y;
}

int Calculator::subtract(int x, int y){
	cout << "Subtraction result of x: " << x << " and y: " << y << " is: " << x-y << endl;
	return x-y;
}

int Calculator::multiply(){
	cout << "Multiplication result of x: " << x << " and y: " << y << " is: " << x*y << endl;
	return x*y;
}

int Calculator::multiply(int x, int y){
	cout << "Multiplication result of x: " << x << " and y: " << y << " is: " << x*y << endl;
	return x*y;
}

float Calculator::divide(float x, float y){
	cout << "Division result of x: " << x << " and y: " << y << " is: " << x/y << endl;
	return x/y;
}

string Calculator::display(){
	string c = "x value is: " + to_string(x) + " and y value is: " + to_string(y);
	cout << c << endl;
	return c;
}

// 15. Static states of a class and example usage
int Calculator::nextValue = 50;
void Calculator::plus_fifty(){
	cout << "Previous x value is: " << x << endl;
	x = nextValue + x;
	cout << "Next x value is: " << x << endl;
}
