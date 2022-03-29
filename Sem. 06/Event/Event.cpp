#pragma once
#include "Event.h"

Event::Event(const char* name, const Time& begin, const Date& date) : begin(begin), date(date)
{
	setName(name);
}

Event::Event(const char* name, size_t hours, size_t mins, size_t seconds, size_t day, size_t month, size_t year) : begin(hours, mins, seconds), date(day, month, year)
{
	setName(name);
}


void Event::setName(const char* name)
{
	if (strlen(name) > 19)
		strcpy(this->name, "Unknown");
	else
		strcpy(this->name, name);
}


const Time& Event::getTime() const
{
	return begin;
}
const Date& Event::getDate() const
{
	return date;
}

const char* Event::getName() const
{
	return name;
}

int Event::getEventsDayOfWeek()
{
	return date.getDayOfWeek();
}

void Event::print() const
{
	std::cout << "Event: " << name << ", date: ";
	date.print();
	std::cout << ", time: ";
	begin.print(true);
	std::cout << std::endl;
}