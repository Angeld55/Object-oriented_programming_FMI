#include "Dog.h"
#include <iostream>

void Dog::roar() const
{
	std::cout << "wof wof" << std::endl;
}

Animal* Dog::clone() const
{
	return new Dog(*this);
}

int Dog::getType() const
{
	return 1;
}