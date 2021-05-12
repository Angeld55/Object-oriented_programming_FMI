#pragma once

class Person
{
public:
	Person();
	Person(const char* name, int age);

	Person(const Person& other);

	Person(Person&& other); //move constr
	
	Person& operator=(Person&& other); // move op=

	Person& operator=(const Person& other);
	~Person();

	void setName(const char* name);
	void setAge(int age);

	const char* getName() const;
	int getAge() const;

	void print();


private:

	void copyFrom(const Person& other);
	void free();


	char* name;
	int age;
};