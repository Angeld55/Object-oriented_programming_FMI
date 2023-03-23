#include "Date.h"

Date::Date(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

unsigned Date::getDay() const
{
	return day;
}
unsigned Date::getMonth() const
{
	return month;
}
unsigned Date::getYear() const
{
	return year;
}

void Date::setYear(unsigned year)
{
	if (year == this->year)
		return;
	this->year = year;
	if (isLeapYear())
		MAX_DAYS[1] = 29;
	else
		MAX_DAYS[1] = 28;
	setDay(getDay());

	isModified = true;

}
void Date::setDay(unsigned day)
{
	if (day == this->day)
		return;

	if (day == 0 || day > MAX_DAYS[month - 1])
		day = 1;
	this->day = day;

	isModified = true;
}
void Date::setMonth(unsigned month)
{
	if (month == this->month)
		return;

	if (month == 0 || month > 12)
		month = 1;
	this->month = month;
	setDay(getDay());

	isModified = true;
}
void Date::goToNextDay()
{
	if (year == 1916 && month == 3 && day == 31)
	{
		setDay(14);
		setMonth(4);
		return;
	}

	setDay(getDay() + 1);
	if (day == 1)
	{
		setMonth(getMonth() + 1);
		if (month == 1)
			setYear(getYear() + 1);
	}
}

int Date::getDayOfWeek() const
{
	if (!isModified)
		return dayOfWeek;

	Date d(1, 1, 1);
	int day = 5; //0 for monday, 6 for sunday

	while (!isEqualTo(d))
	{
		d.goToNextDay();
		day++;
		day %= 7;
	}
	dayOfWeek = day + 1; //1 for monday, 7 fo sunday
	isModified = false;
	return dayOfWeek;
}

bool Date::isEqualTo(const Date& other) const
{
	return day == other.day &&
		month == other.month &&
		year == other.year;
}

void Date::print() const
{
	std::cout << day << "." << month << "." << year << std::endl;
}


bool Date::isLeapYear() const
{
	if (year <= 1916)
		return year % 4 == 0;
	else
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}