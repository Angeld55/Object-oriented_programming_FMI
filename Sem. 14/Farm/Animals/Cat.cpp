#include "Cat.h"

void Cat::sayHello() const 
{
	std::cout << "Hello, I am a Cat!" << std::endl;
}

Animal* Cat::clone() const 
{
	Animal* newObj = new Cat(*this); //copy constr of Mouse
	return newObj;
}