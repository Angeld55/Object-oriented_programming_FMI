#pragma once
#include<iostream>

class Time {
private:
	size_t seconds;
	size_t minutes;
	size_t hours;
public:
	//construct:

	//default constructor:
	Time() : Time(0, 0, 0) {};

	//parameter constructor:
	Time(size_t hrs, size_t mins, size_t sec);

	//copy constructor:
	Time(const Time&);
	
	//get:
	size_t getSeconds()const;
	size_t getMinutes() const;
	size_t getHours() const;

	//set:
	void setSeconds(size_t second);
	void setMinutes(size_t mins);
	void setHours(size_t hrs);

	//functions (helpers):
	void print(std::ostream&) const;

	void addSeconds(size_t sec);
	void addMinutes(size_t min);
	void addHours(size_t hrs);

	Time timeToMidnight();
	Time diff(const Time& arg);

	bool isItTimeForDinner() const;
	bool isItTimeForParty() const;

	int compareTo(const Time& arg) const;

	Time& operator=(const Time& other);
	bool operator==(const Time& other) const;

	//Destruct
	~Time();

private:
	size_t convertTimeToSeconds() const;
	void setTimeBySeconds(size_t seconds);
	bool isItBetweenInterval(const Time& startingPoint, const Time& endingPoint) const;
	bool isItBefore(const Time& startingPoint) const;
};

