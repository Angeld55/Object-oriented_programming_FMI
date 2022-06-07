#include <iostream>
#include <exception>
#include "MyString/MyString.h"
#include "ExpessionCalculator/ExpressionCalculator.h"

int main()
{
	ExpressionCalculator calc("(Pv(!P))");
	std::cout << calc.isTautology();
}