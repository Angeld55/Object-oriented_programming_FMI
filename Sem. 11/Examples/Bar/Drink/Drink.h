#pragma once
#include "../MyString/MyString.h"

class Drink
{
public:

	Drink();
	Drink(const MyString& name, int ml);

	const MyString& getName() const;
	int getMl() const;

	void setName(const MyString& name);
	void setMl(int ml);

private:
	MyString name;
	int ml;

};