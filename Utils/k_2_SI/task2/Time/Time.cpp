#include "Time.h"


void Time::setHours(size_t hours)
{
	if (hours > 24)
		hours = 24;
	this->hours = hours;
}
void Time::setMins(size_t mins)
{
	if (mins > 59)
		mins = 59;
	this->mins = mins;
}
Time::Time(size_t hours, size_t mins)
{
	setHours(hours);
	setMins(mins);
}

bool operator<=(const Time& lhs, const Time& rhs)
{
	return lhs.getHours() * 60 + lhs.getMins() < rhs.getHours() * 60 + rhs.getMins();
}


Time operator-(const Time& lhs, const Time& rhs)
{
	int res = lhs.getHours() * 60 + lhs.getMins() - (rhs.getHours() * 60 + rhs.getMins());

	if (res < 0)
		return Time(0, 0);
	else
		return Time(res / 60, res % 60);
}


size_t Time::getMins() const
{
	return mins;
}
size_t Time::getHours() const
{
	return hours;
}

Time operator+(const Time& lhs, const Time& rhs)
{
	int res = lhs.getHours() * 60 + lhs.getMins() + rhs.getHours() * 60 + rhs.getMins();
	if (res > 24 * 60)
		return Time(0, 0);
	else
		return Time(res / 60, res % 60);
}