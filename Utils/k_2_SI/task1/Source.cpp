#include <iostream>
#include "PairOfOptionals/PairOfOptionals.hpp"

int main()
{
	PairOfOptionals<int, char> p1(5, 's');
	p1.removeSecond();

	p1.setFirst(1);

	PairOfOptionals<int, char> p2;
	std::cout << (p1 == p2) << std::endl;

	p2.setFirst(1);

	std::cout << (p1 == p2);
}