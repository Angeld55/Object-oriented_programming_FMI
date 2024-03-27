#include "Event.h"
#pragma warning(disable : 4996)


Event::Event(const char* name, const Date& date, const Time& startTime, const Time& endTime) : _date(date), _startTime(startTime), _endTime(endTime)
{
	setName(name);
	validateTimes();
}

Event::Event(const char* name, unsigned day, unsigned month, unsigned year,
			 unsigned startTimeHours, unsigned startTimeMins, unsigned startTimeSecs,
			  unsigned endTimeHours, unsigned endTimeMins, unsigned endTimeSecs) : _date(day, month, year),
									                       _startTime(startTimeHours, startTimeMins, startTimeSecs),
											       _endTime(endTimeHours, endTimeMins, endTimeSecs)
{ 
	setName(name);
	validateTimes();
}
const char* Event::getName() const
{
	return _name;
}
const Date& Event::getDate() const
{
	return _date;
}
const Time& Event::getStartTime() const
{
	return _startTime;
}
const Time& Event::getEndTime() const
{
	return _endTime;
}

void Event::setName(const char* str)
{
	if (strlen(str) > 20)
		return;
	else
		strcpy(_name, str);
}
void Event::validateTimes()
{
	if (compareTimes(_startTime, _endTime) <= -1)
		std::swap(_startTime, _endTime);
}

Event::Event() : Event("", 1, 1, 1, 0, 0, 0, 0, 0, 0) {}
