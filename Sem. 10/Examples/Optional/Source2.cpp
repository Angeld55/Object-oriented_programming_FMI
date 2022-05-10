#include <iostream>
#include "Optional.hpp"



int main()
{
	Optional<int> d; //no value

	d.setData(3);

	d.getData();

	d.clear();
	

	std::cout << d.containsData();

}
