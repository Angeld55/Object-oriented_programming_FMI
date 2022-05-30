#include "Dog.h"

void Dog::sayHello() const 
{
	std::cout << "Hello, I am a Dog!" << std::endl;
}

Animal* Dog::clone() const
{
	Animal* newObj = new Dog(*this); //copy constr of Mouse
	return newObj;
}