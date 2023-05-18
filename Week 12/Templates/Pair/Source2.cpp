#include <iostream>
#include "Pair.hpp"



int main()
{
	Pair<int, char> p(3, 'd');

	std::cout << p.getSecond();

	p.setSecond('a');

}
