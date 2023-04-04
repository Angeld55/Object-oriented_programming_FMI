#include "Passenger.h"
#pragma warning (disable : 4996)

Passenger::Passenger() : name(""), age(0) {}

Passenger::Passenger(const char* name, int age)
{
	strcpy(this->name, name);
	this->age = age;
}

const char* Passenger::getName() const
{
	return name;
}

int Passenger::getAge() const
{
	return age;
}

bool Passenger::isStudent() const
{
	return age < 18;
}