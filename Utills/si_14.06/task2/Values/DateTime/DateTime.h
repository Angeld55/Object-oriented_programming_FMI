#pragma once

#include "../Date/Date.h"
#include "../Time/Time.h"

class DateTime : public Date, public Time
{
public:
	DateTime(const std::string& name, size_t day, size_t month, size_t year, size_t hours, size_t mins);
	
	std::string toString() const;

	Value* clone() const; 
};