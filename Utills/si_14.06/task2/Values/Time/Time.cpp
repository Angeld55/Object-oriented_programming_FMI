#include "Time.h"

//validation is needed for the time fields!
Time::Time(const std::string& name, unsigned hours, unsigned mins) : Value(name), hours(hours), mins(mins)
{}

std::string Time::getTimeString() const
{
	return std::to_string(hours) + ":" + std::to_string(mins);
}
std::string Time::toString() const
{
	return getPrefix() + getTimeString() + "}";
}

Value* Time::clone() const
{
	return new Time(*this);
}