#include "Mouse.h"

void Mouse::sayHello() const
{
	std::cout << "Hello, I am a Mouse!" << std::endl;
}

Animal* Mouse::clone() const
{
	Animal* newObj = new Mouse(*this); //copy constr of Mouse
	return newObj;
}