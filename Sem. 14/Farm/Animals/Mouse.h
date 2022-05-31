#pragma once
#include "Animal.h"
class Mouse : public Animal
{
public:
	Mouse()
	{
		myType = Animal::AnimalType::Mouse;
	}
	void sayHello() const override;
	Animal* clone() const override;
};