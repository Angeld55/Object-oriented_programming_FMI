#pragma once
class Animal
{
public:
	virtual void roar() const = 0; //оставаме я без имплементация
	virtual Animal* clone() const = 0; //връща мое копие
	virtual int getType() const = 0;
	virtual ~Animal() = default;
};

