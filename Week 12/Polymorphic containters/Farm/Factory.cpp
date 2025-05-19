#include "Factory.h"
#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"


Animal* animalFactory() 
{
	int type;
	std::cin >> type;

	switch (type)
	{
	case 0: return new Dog();
	case 1: return new Cow();
	case 2: return new Cat();
	default:
		return nullptr;
		break;
	}

}