#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	Dog();
	void roar() const override;
	Animal* clone() const override;
};