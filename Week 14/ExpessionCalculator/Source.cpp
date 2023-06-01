#include <iostream>
#include <exception>
#include "MyString/MyString.h"
#include "ExpressionCalculator.h"

int main()
{
	ExpressionCalculator calc("(Pv(!P))");
	std::cout << calc.isTautology();
}