#include "Animal.hpp"
class Cow : public Animal
{
public:
	Cow(String name) :Animal(name)
	{}
	Animal* clone()
	{
		Animal* copy = new Cow(*this);
		return copy;
	}
	void Roar()
	{
		std::cout << "muu mmuu" << std::endl;
	}
};