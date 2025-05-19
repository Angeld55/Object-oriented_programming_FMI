#include "Cat.h"
#include <iostream>

void Cat::roar() const
{
	std::cout << "meow mewo" << std::endl;
}

Animal* Cat::clone() const
{
	return new Cat(*this);
}

int Cat::getType() const
{
	return 0;
}
