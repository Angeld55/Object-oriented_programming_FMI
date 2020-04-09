#include <iostream>

class Time
{
	int seconds;
	int mins;
	int hours;
public:
	Time(int hours, int mins, int seconds);
	//Time(); 
	int getSeconds() const;
	int getMins() const;
	int getHours() const;
	void setSeconds(int seconds);
	void setMins(int mins);
	void setHours(int hours);

	void print() const;

	int CompareTo(const Time& other) const;
};
