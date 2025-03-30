#pragma once

enum class Month
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum class DayOfWeek
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

class BulgarianDate
{
    unsigned MAX_DAYS[12] =
    {
        31,28,31,30,31,30,31,31,30,31,30,31
    };
    unsigned day = 1;
    Month month = Month::January;
    unsigned year = 1;
    
    bool isLeapYear() const;
    void validateDate();
    bool isDateInValidState = true;
    mutable bool isModified = true; //member that can be modified from CONST functions!! 
    mutable int dayOfWeek = -1;

public:
    BulgarianDate();
    BulgarianDate(unsigned day, unsigned month, unsigned year);
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;
    void setDay(unsigned day);
    void setMonth(unsigned month);
    void setYear(unsigned year);
    void print() const;
    void goToNextDay();
    DayOfWeek getDayOfWeek() const;
    bool good() const;
    void clear();
};

int compareBulgarianDates(const BulgarianDate& lhs, const BulgarianDate& rhs);
