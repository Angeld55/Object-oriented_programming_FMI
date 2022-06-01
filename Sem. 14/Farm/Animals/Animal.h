#pragma once
#include <iostream>
class Animal
{

public:

	enum AnimalType
	{
		Dog = 0,
		Cat = 1,
		Mouse = 2
	};
	virtual void sayHello() const = 0;

	virtual Animal* clone()  const = 0;//създава копие на текущия обект.

	virtual ~Animal() = default; //!!!

	AnimalType getType() const
	{
		return myType;
	}

protected:
	AnimalType myType;
};
