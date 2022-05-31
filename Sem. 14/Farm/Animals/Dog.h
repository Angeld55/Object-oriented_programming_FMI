#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	Dog()
	{
		myType = Animal::AnimalType::Dog;
	}
	void sayHello() const override;
	Animal* clone() const override;
};