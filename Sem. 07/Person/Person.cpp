#include <iostream>
#include "Person.h"

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}


void Person::setName(const char* name)
{
	if (strlen(name) >= 20)
	{
		strcpy(this->name, "Unknown");
	}
	else
	{
		strcpy(this->name, name);
	}
}

void Person::setAge(int age)
{
	if (age<0 || age > 120)
		age = 40;
	this->age = age;
}
const char* Person::getName() const
{
	return name;
}
int Person::getAge() const
{
	return age;
}
void Person::print()
{
	std::cout << name << " " << age << std::endl;
}