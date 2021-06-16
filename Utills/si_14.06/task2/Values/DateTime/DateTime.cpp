#include "DateTime.h"

DateTime::DateTime(const std::string& name, size_t day, size_t month, size_t year, size_t hours, size_t mins) : Value(name), Date(name, day, month, year), Time(name, hours,mins)
{}

std::string DateTime::toString() const
{
	return getPrefix() + getDateString() + ", " + getTimeString() + "}";
}

Value* DateTime::clone() const
{
	return new DateTime(*this);
}