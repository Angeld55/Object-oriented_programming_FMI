#pragma once

#include "../ValueBase/Value.h"

class Date : public virtual Value
{
	unsigned day;
	unsigned month;
	unsigned year;

protected:

	std::string getDateString() const;

public:

	Date(const std::string& name, unsigned day, unsigned month, unsigned year);

	Value* clone() const;

	std::string toString() const;
};