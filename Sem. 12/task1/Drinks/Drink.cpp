#pragma warning(disable: 4996)
#include "Drink.h"
#include <iostream>

Drink::Drink() : Drink("Unknown", 0)
{}
const char* Drink::getName() const
{
	return name;
}
int Drink::getMl() const
{
	return ml;
}

void Drink::setName(const char* name)
{
	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}
void Drink::setMl(int ml)
{
	const int MAX_ML = 1000;
	const int MIN_ML = 100;

	ml = MIN_ML;
	if (MIN_ML <= ml && ml <= MAX_ML)
		this->ml = ml;

}

Drink::Drink(const char* name, int ml) : name(nullptr)
{
	setName(name);
	setMl(ml);
}

Drink::Drink(const Drink& other)
{
	copyFrom(other);
}
Drink& Drink::operator = (const Drink& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Drink::~Drink()
{
	free();
}
void Drink::copyFrom(const Drink& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	ml = other.ml;
}
void Drink::free()
{
	delete[] name;
	ml = 0;
}