#pragma once
#include "Animal.h"
class Mouse : public Animal
{
public:
	void sayHello() const override;
	Animal* clone() const override;
};