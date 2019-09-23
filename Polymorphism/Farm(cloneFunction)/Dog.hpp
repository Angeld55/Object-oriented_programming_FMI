#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(string name) :Animal(name)
	{}
	void Roar()
	{
		std::cout << "bau bau" << std::endl;
	}
	Animal* clone()
	{
		Animal* copy = new Dog(*this);
		return copy;
	}

};
