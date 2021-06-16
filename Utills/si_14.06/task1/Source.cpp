#include  <iostream>
#include "Optional/Optional.hpp"



int main()
{
	Optional<int> o;

	std::cout << o.containsValue() << std::endl;

	o.setValue(12);

	Optional<int> o2(12);

	std::cout << (o == o2) << std::endl;
}