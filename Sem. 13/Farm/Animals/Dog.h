#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	void sayHello() const override;
	Animal* clone() const override;
};