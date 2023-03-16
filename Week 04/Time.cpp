#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
	unsigned hours; //[0...23]
	unsigned mins; // [0...59]
	unsigned seconds; //[0...59]

	bool isInInterval(unsigned upperInterval, unsigned value)
	{
		return value <= upperInterval;
	}
public:
	Time(unsigned hours, unsigned mins, unsigned seconds)
	{
		setHours(hours);
		setMins(mins);
		setSeconds(seconds);
	}
	Time() : Time(0,0,0)
	{}

	Time(unsigned secondsFromMidnight) //4000 - 3600
	{
		if (!isInInterval(24 * 3600, secondsFromMidnight))
			secondsFromMidnight = 0;

		setHours(secondsFromMidnight / 3600);
		secondsFromMidnight %= 3600;

		setMins(secondsFromMidnight / 60);
		secondsFromMidnight %= 60;

		setSeconds(secondsFromMidnight);
	}

	void setHours(unsigned hours) //Колизия при имена
	{
		if (isInInterval(23, hours))
			this->hours = hours;
		else
			this->hours = 0;
	}
	void setMins(unsigned mins) //Колизия при имена
	{
		if (isInInterval(59, mins))
			this->mins = mins;
		else
			this->mins = 0;
	}
	void setSeconds(unsigned seconds) //Колизия при имена
	{
		if (isInInterval(59, seconds))
			this->seconds = seconds;
		else
			this->seconds = 0;
	}
	unsigned getHours() const
	{
		return hours;
	}
	unsigned getMins() const
	{
		return mins;
	}
	unsigned getSeconds() const
	{
		return seconds;
	}

	unsigned getToSecondsFromMidnight() const
	{
		return hours * 3600 + mins * 60 + seconds;
	}

	void print() const
	{
		std::cout << hours << " : " << mins << " : " << seconds << std::endl;
	}
};

int compareTimes(const Time& lhs, const Time& rhs)
{
	int lhsSeconds = lhs.getToSecondsFromMidnight();
	int rhsSeconds = rhs.getToSecondsFromMidnight();
	return lhsSeconds - rhsSeconds;
}

Time diff(const Time& lhs, const Time& rhs)
{
	int diff = lhs.getToSecondsFromMidnight() - rhs.getToSecondsFromMidnight();
	unsigned diffInSeconds = abs(diff);
	return Time(diffInSeconds);
}

int main()
{
	Time t(12,4,55);

	t.print();

}
