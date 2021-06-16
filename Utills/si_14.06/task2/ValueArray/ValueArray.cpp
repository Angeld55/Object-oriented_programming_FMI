#include <iostream>
#include "ValueArray.h"
#include "../Values/Date/Date.h"
#include "../Values/Time/Time.h"
#include "../Values/String/StringValue.h"
#include "../Values/DateTime/DateTime.h"

void ValueArray::print() const
{
	std::cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i]->toString();

		if (i != arr.size() - 1)
			std::cout << ", ";

	}
	std::cout << "]";
}


void ValueArray::free()
{
	for (int i = 0; i < arr.size(); i++)
		delete arr[i];
	arr.clear();
}

void ValueArray::copyFrom(const ValueArray& other)
{
	arr.resize(other.arr.size());

	for (int i = 0; i < arr.size(); i++)
		arr[i] = other.arr[i]->clone();
}

void ValueArray::addDate(const std::string& name, unsigned day, unsigned month, unsigned year)
{
	arr.push_back(new Date(name, day, month, year));
}
void ValueArray::addTime(const std::string& name, unsigned hours, unsigned mins)
{
	arr.push_back(new Time(name, hours, mins));
}
void ValueArray::addString(const std::string& name, const std::string& value)
{
	arr.push_back(new StringValue(name,value));
}
void ValueArray::addDateTime(const std::string& name, unsigned day, unsigned month, unsigned year, unsigned hours, unsigned mins)
{
	arr.push_back(new DateTime(name, day, month, year, hours, mins));
}

ValueArray::ValueArray(const ValueArray& other)
{
	copyFrom(other);
}
ValueArray& ValueArray::operator= (const ValueArray& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ValueArray::~ValueArray()
{
	free();
}