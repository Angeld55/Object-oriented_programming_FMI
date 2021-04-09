#include "PersonAdvanced.h"
#include <iostream>

PersonAdvanced::PersonAdvanced(const char* name, int age) : name(nullptr), age(age)
{
	setName(name);
	setAge(age);
}

PersonAdvanced::PersonAdvanced(const PersonAdvanced& other)
{
	copyFrom(other);
}

PersonAdvanced& PersonAdvanced::operator = (const PersonAdvanced& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
PersonAdvanced::~PersonAdvanced()
{
	free();
}

const char* PersonAdvanced::getName() const
{
	return name;
}

int PersonAdvanced::getAge() const
{
	return age;
}

void PersonAdvanced::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void PersonAdvanced::setAge(int age)
{
	if (age < 0 || age > 120)
		age = 40;
	this->age = age;
}


void PersonAdvanced::copyFrom(const PersonAdvanced& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;
}
void PersonAdvanced::free()
{
	delete[] name;
	age = 0;
}