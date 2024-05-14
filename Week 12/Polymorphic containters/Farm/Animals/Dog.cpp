#include "Dog.h"

Dog::Dog() : Animal(AnimalType::Dog)
{}

void Dog::roar() const
{
	std::cout << "Wof wof" << std::endl;
}

Animal* Dog::clone() const
{
	Animal* newObj = new (std::nothrow) Dog(*this); //copy constr of Mouse
	return newObj;
}