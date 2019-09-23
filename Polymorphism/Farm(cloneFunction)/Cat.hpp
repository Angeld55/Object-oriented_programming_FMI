#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat(string name) :Animal(name)
	{}
	Animal* clone()
	{
		Animal* copy = new Cat(*this);
		return copy;
	}
	void Roar()
	{
		std::cout << "meow meow" << std::endl;
	}
};
