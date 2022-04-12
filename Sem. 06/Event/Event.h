#pragma once
#include "Date.h"
#include "Time.h"
class Event
{
	char name[20];
	Time begin;
	Date date;

	void setName(const char* name);

public:
	Event(const char* name, const Time& begin, const Date& date);
	Event(const char* name, size_t hours, size_t mins, size_t seconds, size_t day, size_t month, size_t year);

	const Time& getTime() const;
	const Date& getDate() const;
	const char* getName() const;

	void print() const;

	int getEventsDayOfWeek() const; //can't be const (date.getDayOfWeek is not a constant function)
							  // how can we fix it ???
};