#ifndef CALCULATOR_H_
#define CALCULATOR_H_

using std::string;

class Calculator{
	// 1. Correct use of all access specifiers
	// 15. Static states of a class and example usage
	static int nextValue; // private by default
protected:
	int x, y;

public:
	Calculator();
	Calculator(int, int);
	virtual ~Calculator();
	virtual int add(int, int);
	virtual int subtract(int, int);
	virtual float divide(float, float);
	virtual int multiply(int, int);
	virtual int multiply();
	virtual void plus_fifty();

	virtual string display();
};

#endif /* CALCULATOR_H_ */
