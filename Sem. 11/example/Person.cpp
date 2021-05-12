#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() : Person("Unknown", 0)
{

}
Person::Person(const char* name, int age) : name(nullptr), age(age)
{
	cout << "Constr" << endl;
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	cout << "copy constr" << endl;
	copyFrom(other);
}
Person::Person(Person&& other)
{
	cout << "Move constr" << endl;

	name = other.name;
	age = other.age;

	other.name = nullptr;
}

Person& Person::operator=(Person&& other)
{

	std::cout << "Move op= " << endl;
	if (this != &other)
	{
		free();
		
		name = other.name;
		other.name = nullptr;

		age = other.age;

	}
	return *this;
}

Person& Person::operator = (const Person& other)
{
	cout << "op =" << endl;
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Person::~Person()
{
	cout << "Destructor" << endl;
	free();
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Person::setAge(int age)
{
	if (age < 0 || age > 120)
		age = 40;
	this->age = age;
}

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;
}
void Person::free()
{
	delete[] name;
	age = 0;
}