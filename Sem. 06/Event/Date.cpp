
#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool Date::isLeapYear() const
{
	if (year <= 1916)
		return year % 4 == 0;
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void Date::validateDateByChangedCalendars() 
{
	if (year == 1916 && month == 4 && day >= 1 && day <= 13) // invalid days due to change in callendars 
		day = 15;
}

Date::Date(size_t day, size_t month, size_t year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}
size_t Date::getDay() const
{
	return day;
}
size_t Date::getMonth() const
{
	return month;
}
size_t Date::getYear() const
{
	return year;
}
void Date::setYear(size_t year)
{
	this->year = year;

	if (isLeapYear())
		MAX_DAYS[1] = 29;
	else
		MAX_DAYS[1] = 28;
	isModified = true;
	validateDateByChangedCalendars();
}
void Date::setMonth(size_t month)
{
	if (month > 12)
	{
		month = 1;
	}
	this->month = month;

	if (day > MAX_DAYS[month - 1])
		day = MAX_DAYS[month - 1];

	isModified = true;
	validateDateByChangedCalendars();
}
void Date::setDay(size_t day)
{
	if (day > MAX_DAYS[month - 1])
	{
		day = 1;
	}
	this->day = day;
	isModified = true;
	validateDateByChangedCalendars();
}
void Date::print() const
{
	std::cout << setw(2) << setfill('0') << day << "." << setw(2) << setfill('0') << month << ".";
	std::cout << setw(4) << setfill('0') << year;
}

void Date::goToNextDay()
{
	if (areEqual(Date(31, 03, 1916)))
	{
		setDay(14);
		setMonth(04);
		return;
	}
	setDay(day + 1);
	if (day == 1)
	{
		setMonth(month + 1);
		if (month == 1)
			setYear(year + 1);
	}
}
bool Date::areEqual(const Date& other) const
{
	return year == other.year && month == other.month && day == other.day;
}

int Date::getDayOfWeek()  const
{

	if (!isModified)
		return dayOfWeek;

	Date d(1, 1, 1);
	int day = 5;

	while (!areEqual(d))
	{
		d.goToNextDay();
		(day += 1) %= 7;

	}
	dayOfWeek = day + 1;
	isModified = false;
	return dayOfWeek;
}