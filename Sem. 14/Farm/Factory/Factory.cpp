#include "Factory.h"


Animal* AnimalFactory::createAnimal(Animal::AnimalType type)
{
	switch (type)
	{
		case Animal::AnimalType::Cat: return new Cat();
		case Animal::AnimalType::Dog: return new Dog();
		case Animal::AnimalType::Mouse: return new Mouse();
	}
	return nullptr;
}
