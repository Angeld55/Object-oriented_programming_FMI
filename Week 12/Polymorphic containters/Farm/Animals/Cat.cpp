#include "Cat.h"

Cat::Cat() : Animal(AnimalType::Cat)
{}

void Cat::roar() const
{
	std::cout << "Meow meow!" << std::endl;
}

Animal* Cat::clone() const 
{
	Animal* newObj = new Cat(*this); //copy constr of Mouse
	return newObj;
}