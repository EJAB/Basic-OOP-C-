#ifndef CALORIES_H_
#define CALORIES_H_
#include "Food.h"
#include "Calculator.h"

class Calories:public Food, public Calculator {

public:
	Calories();
	Calories(int, int, int);
	virtual ~Calories();

	// 4. Example of multiple inheritance - Calculator method multiply() and Food parameters
	void carbs_calories();
	void protein_calories();
	void fat_calories();
	void total();

	// 13. To demonstrate dynamic binding on virtual method
	virtual string display();

	// 13. To demonstrate dynamic binding on non-virtual method
	string dynBind();
};

#endif /* CALORIES_H_ */
