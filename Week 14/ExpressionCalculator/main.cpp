#include <iostream>
#include "ExpressionCalculator.h"

int main() {
	ExpressionCalculator ta("(Pv(!P))");
	ExpressionCalculator c("(P^(!P))");

	std::cout << ta.isTautology() << std::endl;
	std::cout << ta.isContradiction() << std::endl;

	std::cout << c.isTautology() << std::endl;
	std::cout << c.isContradiction() << std::endl;
}