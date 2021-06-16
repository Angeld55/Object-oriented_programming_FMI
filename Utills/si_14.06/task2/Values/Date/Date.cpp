#include "Date.h"

//validation is needed for the date fields!
Date::Date(const std::string& name, unsigned day, unsigned month, unsigned year) : Value(name), year(year), month(month), day(day)
{}

std::string Date::getDateString() const
{
	return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);;
}
std::string Date::toString() const
{
	return getPrefix() + getDateString() + "}";
}

Value* Date::clone() const
{
	return new Date(*this);
}