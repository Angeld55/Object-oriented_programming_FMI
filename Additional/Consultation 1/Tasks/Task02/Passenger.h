#pragma once
#include <iostream>

const unsigned MAX_NAME_SIZE = 20;
class Passenger
{
	char name[MAX_NAME_SIZE];
	int age;

public:
	Passenger();
	Passenger(const char* name, int age);
	const char* getName() const;
	int getAge() const;

	bool isStudent() const;
};