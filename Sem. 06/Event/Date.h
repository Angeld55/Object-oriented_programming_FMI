#pragma once

class Date
{
	size_t day;
	size_t month;
	size_t year;

	size_t MAX_DAYS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	mutable int dayOfWeek; 
	mutable bool isModified = true;

	bool isLeapYear() const;
	void validateDateByChangedCalendars();
public:
	Date(size_t day, size_t month, size_t year);
	
	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;

	void setDay(size_t);
	void setMonth(size_t);
	void setYear(size_t);

	void print() const;
	void goToNextDay();

	bool areEqual(const Date& other) const;

	int getDayOfWeek() const; 
};
