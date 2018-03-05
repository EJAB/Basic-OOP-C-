#include "Chocolate.h"
#include <string>
#include <iostream>

using namespace std;
Chocolate::Chocolate(string aBrand, int aBlock):brand(aBrand), block(aBlock) {}

Chocolate::Chocolate(string aBrand):brand(aBrand), block() {}

Chocolate::~Chocolate() {cout << "Chocolate object is being destroyed" << endl;}

string Chocolate::display(){
	string s = "Brand name: " + brand + " and block count: " + to_string(block);
	cout << s << endl;
	return s;
}
