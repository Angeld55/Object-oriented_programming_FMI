#include "BulgarianDate.h"
#include <iostream>

BulgarianDate::BulgarianDate()
{
    year = 1;
    month = Month::January;
    day = 1;
    validateDate();
}

BulgarianDate::BulgarianDate(unsigned day, unsigned month, unsigned year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

unsigned BulgarianDate::getDay() const
{
    if(!good()) return 0;
    return day;
}

unsigned BulgarianDate::getMonth() const
{
    if(!good()) return 0;
    return static_cast<unsigned>(month);
}

unsigned BulgarianDate::getYear() const
{
    if(!good()) return 0;
    return year;
}

void BulgarianDate::setYear(unsigned year)
{
    if(!good()) return;
    this->year = year;
    if (isLeapYear())
        MAX_DAYS[1] = 29;
    else
        MAX_DAYS[1] = 28;
    isModified = true;
    validateDate();
}

void BulgarianDate::setDay(unsigned day)
{
    if(!good()) return;
    this->day = day;
    isModified = true;
    validateDate();
}

void BulgarianDate::setMonth(unsigned month)
{
    if(!good()) return;
    this->month = static_cast<Month>(month);
    isModified = true;
    validateDate();
}

void BulgarianDate::goToNextDay()
{
    if(!good()) return;
    if (year == 1916 && static_cast<unsigned>(month) == 3 && day == 31)
    {
        day = 14;
        month = Month::April;
    }
    else
    {
        day++;
        if (day > MAX_DAYS[static_cast<unsigned>(month) - 1])
        {
            day = 1;
            setMonth(static_cast<unsigned>(month) == 12 ? 1 : (static_cast<unsigned>(month) + 1));
            if (static_cast<unsigned>(month) == 1)
                setYear(year + 1);
        }
    }
    isModified = true;
}

DayOfWeek BulgarianDate::getDayOfWeek() const
{
    if(!good()) return static_cast<DayOfWeek>(-1);
    if (!isModified)
        return static_cast<DayOfWeek>(dayOfWeek);
	
    BulgarianDate d(1,1,1);
    int day = 5;
    while (compareBulgarianDates(d, *this) != 0)
    {
        d.goToNextDay();
        day++;
        day %= 7;
    }
    dayOfWeek = day + 1;
    isModified = false;
    return static_cast<DayOfWeek>(dayOfWeek);
}

void BulgarianDate::print() const
{
    if(!good()) return;
    std::cout << day << "." << static_cast<unsigned>(month) << "." << year << std::endl;
}

bool BulgarianDate::isLeapYear() const
{
    if (year <= 1916)
        return year % 4 == 0;
    else
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BulgarianDate::validateDate()
{
    isDateInValidState = !((static_cast<unsigned>(month) == 0 || static_cast<unsigned>(month) > 12) ||
                           (day == 0 || day > MAX_DAYS[static_cast<unsigned>(month) - 1]) ||
                           (year == 0) ||
                           (year == 1916 && static_cast<unsigned>(month) == 4 && day < 14));
}

bool BulgarianDate::good() const
{
    return isDateInValidState;
}

void BulgarianDate::clear()
{
    isDateInValidState = true;
    day = 1;
    month = Month::January;
    year = 1;
}

int compareBulgarianDates(const BulgarianDate& lhs, const BulgarianDate& rhs)
{
    if (lhs.getYear() < rhs.getYear())
    {
        return -1;
    }
    else if (lhs.getYear() > rhs.getYear())
    {
        return 1;
    }
    else
    {
        if (lhs.getMonth() < rhs.getMonth())
        {
            return -1;
        }
        else if (lhs.getMonth() > rhs.getMonth())
        {
            return 1;
        }
        else
        {
            if (lhs.getDay() < rhs.getDay())
            {
                return -1;
            }
            else if (lhs.getDay() > rhs.getDay())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}
