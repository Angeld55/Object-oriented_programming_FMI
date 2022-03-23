#include <iostream>
using namespace std;

class Time
{
	size_t seconds; //[0...59]
	size_t mins; //0...59
	size_t hours; // 0...23

	size_t convertToSeconds() const
	{
		return 3600 * hours + 60 * mins + seconds;
	}


public:
	Time(); // 00:00:00
	Time(size_t hours, size_t mins, size_t seconds);
	Time(size_t seconds);


	size_t getSeconds() const;
	size_t getMins() const;
	size_t getHours() const;

	void setSeconds(size_t seconds);
	void setMins(size_t mins);
	void setHours(size_t hours);

	void tick();
	
	int compare(const Time& other) const;
	Time getDiff(const Time& other) const;

	Time getToMidnight() const;
	bool isPartyTime() const;//23:00  05;00
	bool isDinnerTime() const;//19:30  21:30

	void print(bool is12hoursclock) const;

};
Time::Time(size_t hours, size_t mins, size_t seconds)
{
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}

Time::Time() : Time(0,0,0)
{}

Time::Time(size_t seconds)
{
	hours = seconds / 3600;
	seconds %= 3600;

	mins = seconds / 60;
	seconds %= 60;

	this->seconds = seconds;
}


size_t Time::getSeconds() const
{
	return seconds;
}
size_t Time::getMins() const
{
	return mins;
}
size_t Time::getHours() const
{
	return hours;
}

void Time::setSeconds(size_t seconds)
{
	if (seconds > 59)
		seconds = 59;
	this->seconds = seconds;
}
void Time::setMins(size_t mins)
{
	if (mins > 59)
		mins = 59;
	this->mins = mins;
}
void Time::setHours(size_t hours)
{
	if (hours > 23)
		hours = 23;
	this->hours = hours;
}

void Time::tick()
{
	size_t seconds = convertToSeconds();
	seconds++;
	Time newObj(seconds);

	*this = newObj; //копие
}

int Time::compare(const Time& other) const
{
	size_t mySeconds = convertToSeconds();
	size_t otherSeconds = other.convertToSeconds();

	if (mySeconds > otherSeconds)
		return 1;
	else if (mySeconds < otherSeconds)
		return -1;
	else
		return 0;
}
Time Time::getDiff(const Time& other) const
{
	size_t mySeconds = convertToSeconds();
	size_t otherSeconds = other.convertToSeconds();

	size_t diff;

	if (mySeconds > otherSeconds)
		diff = mySeconds - otherSeconds;
	else
		diff = otherSeconds - mySeconds;

	return Time(diff);
}

Time Time::getToMidnight() const
{
	Time midnight(23, 59, 59);
	Time diff = getDiff(midnight);
	diff.tick();
	return diff;
}
bool Time::isDinnerTime() const
{
	Time lowerBound(20, 30, 0);
	Time upperBound(22, 0, 0);
	return compare(lowerBound) >= 0 && compare(upperBound) <= 0;
}
bool Time::isPartyTime() const
{
	Time lowerBound(23, 0, 0);
	Time upperBound(6, 0, 0);
	return compare(lowerBound) >= 0 || compare(upperBound) <= 0;
}

void Time::print(bool is12hoursclock) const
{
	if (hours < 10)
		std::cout << 0;
	std::cout << ((is12hoursclock && hours > 12) ? hours - 12 : hours) << ":";
	if (mins < 10)
		std::cout << 0;
	std::cout << mins << ":";
	if (seconds < 10)
		std::cout << 0;
	std::cout << seconds;
	if (is12hoursclock)
		std::cout << ((hours > 12) ? "PM" : "AM");
	std::cout << std::endl;
}

void swap(Time& first, Time& second)
{
	Time& temp = first;
	first = second;
	second = temp;
}
void timeBubbleSort(Time* arr, size_t arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < arrLen - 1 - i; j++)
		{
			if (arr[j].compare(arr[j + 1]) > 0)
			{
				swap(arr[j],arr[j+1]);
				isSwapped = true;
			}
		}
		
		if(!isSwapped)
			return;
	}
}

int main()
{
	Time times[10] = { Time(11, 30, 0), Time(12, 44, 29), Time(), Time(17, 15, 23), Time(23, 60, 0), Time(3, 14, 15), Time(2, 71, 82), Time(21, 22, 3), Time(17, 15, 23), Time(7, 31, 43) };
	timeBubbleSort(times, 10);
	for (int i = 0; i < 10; i++)
		times[i].print(false);
}
