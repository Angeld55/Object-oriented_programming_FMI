#include "Cow.h"
#include <iostream>

void Cow::roar() const
{
	std::cout << "muu muu" << std::endl;
}

Animal* Cow::clone() const
{
	return new Cow(*this);
}

int Cow::getType() const
{
	return 2;
}