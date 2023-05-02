#pragma once
#include <iostream>
class Person
{
	char* name = nullptr;
	int age = 0;

	void copyFrom(const Person& other);
	void free();
	void moveFrom(Person&& other);

public:
	Person() = default;
	Person(const char* name, int age);

	Person(const Person& other);
	Person& operator=(const Person& other);

	Person(Person&& other);
	Person& operator=(Person&& other);

	const char* getName() const;
	int getAge() const;

	~Person();
	void print() const;

protected:
	void setName(const char* name);
	void setAge(int age);
};
