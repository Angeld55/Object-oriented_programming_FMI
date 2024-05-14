#include "Cow.h"

Cow::Cow() : Animal(AnimalType::Cow)
{}

void Cow::roar() const
{
	std::cout << "Muu muu!" << std::endl;
}

Animal* Cow::clone() const
{
	Animal* newObj = new (std::nothrow) Cow(*this); //copy constr of Cow
	return newObj;
}