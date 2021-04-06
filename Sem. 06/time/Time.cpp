#include "Time.h"

Time::Time(size_t hrs, size_t mins, size_t sec)
{
	this->setSeconds(sec);
	this->setMinutes(mins);
	this->setHours(hrs);
}

Time::Time(const Time& other)
{
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
}

size_t Time::getSeconds() const
{
	return this->seconds;
}

size_t Time::getMinutes() const
{
	return this->minutes;
}

size_t Time::getHours() const
{
	return this->hours;
}

void Time::setSeconds(size_t second)
{
	if (second >= 60) 
	{
		second = 0;
	}

	this->seconds = second;
}

void Time::setMinutes(size_t mins)
{
	if (mins >= 60)
	{
		mins = 0;
	}
	this->minutes = mins;
}

void Time::setHours(size_t hrs)
{
	if (hrs >= 24)
	{
		hrs = 0;
	}

	this->hours = hrs;
}

//Taking an ostream parameter because we don't want to force user to use std::cout.
//Printing happens by passing std::cout as an argument (T.print(std::cout));
void Time::print(std::ostream& out) const
{
	out << this->hours << ":" << this->minutes << ":" << this->seconds << std::endl;
}

void Time::addSeconds(size_t sec)
{
	size_t currTime = convertTimeToSeconds();
	currTime += sec;
	setTimeBySeconds(currTime);
}

void Time::addMinutes(size_t min)
{
	addSeconds(60 * min);
}

void Time::addHours(size_t hrs)
{
	addSeconds(3600 * hrs);
}

Time Time::timeToMidnight()
{
	size_t timeLeft = 24 * 3600 - (this->hours * 3600 + this->minutes * 60 + this->seconds);
	Time toReturn;
	toReturn.setTimeBySeconds(timeLeft);
	return toReturn;
}

Time Time::diff(const Time& arg)
{
	size_t rSecs = this->seconds;
	size_t rMins = this->minutes;
	size_t rHrs = this->hours;

	if (this->seconds < arg.seconds) 
	{
		rSecs += 60;
		rMins--;
	}

	rSecs = rSecs - arg.seconds;

	if (rMins < arg.minutes)
	{
		rMins += 60;
		rHrs--;
	}

	rMins = rMins - arg.minutes;

	if (rHrs < arg.hours)
	{
		rHrs += 24;
	}

	rHrs = rHrs - arg.hours;

	Time toReturn(rHrs, rMins, rSecs);

	return toReturn;
}

bool Time::isItTimeForDinner() const
{
	Time start(20, 30, 00);
	Time end(21, 59, 59);
	return isItBetweenInterval(start, end);
}

bool Time::isItTimeForParty() const
{
	Time start(23, 00, 00);
	Time end(23, 59, 59);
	Time startTwo(0, 0, 0);
	Time endTwo(5, 59, 59);

	return isItBetweenInterval(start, end) || isItBetweenInterval(startTwo, endTwo);
}

int Time::compareTo(const Time& arg) const
{
	if (*this == arg)
	{
		return 0;
	}

	if (isItBefore(arg))
	{
		return 1;
	}

	return -1;
}

Time& Time::operator=(const Time& other)
{
	if (this == &other)
	{
		return *this;
	}

	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;

	return *this;
}


bool Time::operator==(const Time& other) const
{
	return this->hours == other.hours && this->minutes == other.minutes
		&& this->seconds == other.seconds;
}

Time::~Time()
{
}

bool Time::isItBefore(const Time& timePoint) const
{
	return this->hours > timePoint.hours ||
		(this->hours == timePoint.hours && this->minutes > timePoint.minutes) ||
		(this->hours == timePoint.hours && this->minutes == timePoint.minutes && this->seconds > timePoint.seconds);
}

bool Time::isItBetweenInterval(const Time& startingPoint, const Time& endingPoint) const
{
	return isItBefore(startingPoint) && !isItBefore(endingPoint);
}

size_t Time::convertTimeToSeconds() const
{
	return hours * 3600 + minutes * 60 + seconds;
}

void Time::setTimeBySeconds(size_t secs)
{
	this->hours = secs / 3600;
	secs %= 3600;

	while (hours >= 24)
	{
		hours -= 24;
	}

	this->minutes = secs / 60;
	secs %= 60;

	while (minutes >= 60) 
	{
		minutes -= 60;
		this->addHours(1);
	}

	this->seconds = secs;

	while (seconds >= 60) 
	{
		seconds -= 60;
		this->addMinutes(1);
	}
}