#include "Drink.h"

Drink::Drink() : Drink("Unknown", 0)
{}

const MyString& Drink::getName() const
{
	return name;
}
int Drink::getMl() const
{
	return ml;
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool areAllLowerCase(const char* str)
{
	while (*str)
	{
		if (!isLower(*str))
			return false;
		str++;
	}
	return true;
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isNameValid(const char* name)
{
	return isUpper(*name) && areAllLowerCase(name + 1);
}

void Drink::setName(const MyString& name)
{
	if (isNameValid(name.c_str()))
		this->name = name;
}
void Drink::setMl(int ml)
{
	const int MAX_ML = 1000;
	const int MIN_ML = 100;

	ml = MIN_ML;
	if (MIN_ML <= ml && ml <= MAX_ML)
		this->ml = ml;

}

Drink::Drink(const MyString& name, int ml)
{
	setName(name);
	setMl(ml);
}

