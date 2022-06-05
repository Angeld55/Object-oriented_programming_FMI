#pragma once
class Time
{
	size_t hours;
	size_t mins;

	void setHours(size_t hours);
	void setMins(size_t mins);


public:
	Time(size_t hour, size_t min);

	size_t getMins() const;
	size_t getHours() const;
};

bool operator<=(const Time& lhs, const Time& rhs);
Time operator-(const Time& lhs, const Time& rhs);
Time operator+(const Time& lhs, const Time& rhs);
