#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	void roar() const override;
	Animal* clone() const override;
	int getType() const override;
};

