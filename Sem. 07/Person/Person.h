#pragma once

class Person
{
public:
	Person(const char* name, int age);

	void setName(const char* name);
	void setAge(int age);

	const char* getName() const;
	int getAge() const;

	void print();

private:
	char name[20];
	int age;
};
