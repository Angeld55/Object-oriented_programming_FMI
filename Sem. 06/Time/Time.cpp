#include "Time.h"
#include <iostream>

Time::Time() : Time(0, 0, 0){}

Time::Time(size_t hours, size_t mins, size_t seconds)
{
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}

size_t Time::getHours()
{
	return hours;
}
size_t Time::getMins()
{
	return mins;
}
size_t Time::getSeconds()
{
	return seconds;
}
void Time::setHours(size_t hours)
{
	if (hours >= 24)
		hours = 0;
	this->hours = hours;
}
void Time::setMins(size_t mins)
{
	if (mins > 59)
		mins = 0;
	this->mins = mins;
}
void Time::setSeconds(size_t seconds)
{
	if (seconds > 59)
		seconds = 0;
	this->seconds = seconds;
}
void Time::print()
{
	std::cout << hours << ":" << mins << ":" << seconds << std::endl;
}

void Time::addSeconds(size_t seconds)
{
	size_t currentTimeSeconds = convertTimeToSeconds();

	currentTimeSeconds += seconds;

	setTimeBySeconds(currentTimeSeconds);

}
void Time::addMinutes(size_t minutes)
{
	addSeconds(60 * minutes);
}
void Time::addHours(size_t hours)
{
	addMinutes(60 * hours);
}
size_t Time::convertTimeToSeconds()
{
	return hours * 3600 + mins * 60 + seconds;
}
void Time::setTimeBySeconds(size_t seconds) //12000
{
	hours = seconds / 3600;
	seconds %= 3600;

	mins = seconds / 60;
	seconds %= 60;

	this->seconds = seconds;
}