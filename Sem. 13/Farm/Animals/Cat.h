#pragma once
#include "Animal.h"
class Cat : public Animal
{
public:
	void sayHello() const override;
	Animal* clone() const override;
};