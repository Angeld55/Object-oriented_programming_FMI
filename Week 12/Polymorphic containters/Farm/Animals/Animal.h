#pragma once
#include <iostream>

enum class AnimalType
{
	Dog,
	Cat,
	Cow
};
class Animal
{
	AnimalType type;
public:
	
	Animal(AnimalType type) : type(type) {};
	virtual void roar() const = 0;
	virtual Animal* clone()  const = 0;//създава копие на текущия обект.
	virtual ~Animal() = default;


	AnimalType getType() const 
	{
		return type;
	}
	//The problem is that the parrent knows about it's chilldren.
	//You can make this with a pure-virtual getType method, but makes it difficult 
	//to keep the values unique.
};