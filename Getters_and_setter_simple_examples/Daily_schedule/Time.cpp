#include "Time.h"

Time::Time(int hours, int mins, int seconds)
{
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}
/*Time()
{
setHours(0);
setMins(0);
setSeconds(0);
}*/
int Time::getSeconds() const
{
	return seconds;
}
int Time::getMins() const
{
	return mins;
}
int Time::getHours() const
{
	return hours;
}
void Time::print() const
{
	std::cout << hours << " " << mins << " " << seconds << std::endl;
}
void Time::setSeconds(int seconds)
{
	if (seconds < 0 || seconds > 59)
		seconds = 0;
	this->seconds = seconds;
}
void Time::setMins(int mins)
{
	if (mins < 0 || mins > 59)
		mins = 0;
	this->mins = mins;
}
void Time::setHours(int hours)
{
	if (hours < 0 || hours > 23)
		hours = 0;
	this->hours = hours;
}
int Time::CompareTo(const Time& other) const
{
	if (getHours() > other.getHours())
		return -1;
	else if (getHours() < other.getHours())
	{
		return 1;
	}
	else
	{
		if (getMins() > other.getMins())
			return -1;
		else if (getMins() < other.getMins())
			return 1;
		else
		{
			if (getSeconds() > other.getSeconds())
				return -1;
			else if (getSeconds() < other.getSeconds())
				return 1;
			else
				return 0;
		}
	}
}