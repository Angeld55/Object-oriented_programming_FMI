#pragma once

#include "../ValueBase/Value.h"

class Time : public virtual Value
{
	unsigned hours;
	unsigned mins;

protected:
	std::string Time::getTimeString() const;

public:
	Time(const std::string& name, unsigned hours, unsigned mins);

	Value* clone() const;

	std::string toString() const;
};