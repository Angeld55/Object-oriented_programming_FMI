#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(String name) :Animal(name)
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