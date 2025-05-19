#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	void roar() const override;	
	Animal* clone() const override;
	int getType() const override;
};

