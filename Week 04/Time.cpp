#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
	//the best way is to store them in to a single variable (only for seconds). 
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

	Time() : Time(0, 0, 0)
	{}

	Time(unsigned secondsFromMidnight) 
	{
		if (!isInInterval(24 * 3600, secondsFromMidnight))
			secondsFromMidnight = 0;

		setHours(secondsFromMidnight / 3600);
		secondsFromMidnight %= 3600;

		setMins(secondsFromMidnight / 60);
		secondsFromMidnight %= 60;

		setSeconds(secondsFromMidnight);
	}

	void setHours(unsigned hours)
	{
		if (isInInterval(23, hours))
			this->hours = hours;
		else
			this->hours = 0;
	}

	void setMins(unsigned mins)
	{
		if (isInInterval(59, mins))
			this->mins = mins;
		else
			this->mins = 0;
	}

	void setSeconds(unsigned seconds)
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

	unsigned getSecondsFromMidnight() const
	{
		return hours * 3600 + mins * 60 + seconds;
	}

	void print() const
	{
		std::cout << hours << " : " << mins << " : " << seconds << std::endl;
	}

	void tick()
	{
		unsigned seconds = getSecondsFromMidnight();
		seconds++;
		Time newObj(seconds);

		*this = newObj; //копие
	}

	Time getToMidnight() const
	{
		Time midnight(23, 59, 59);
		Time diff = getDiff(midnight);
		diff.tick();
		return diff;
	}

	bool isDinnerTime() const
	{
		Time lowerBound(20, 30, 0);
		Time upperBound(22, 0, 0);
		return compare(lowerBound) >= 0 && compare(upperBound) <= 0;
	}

	bool isPartyTime() const
	{
		Time lowerBound(23, 0, 0);
		Time upperBound(6, 0, 0);
		return compare(lowerBound) >= 0 || compare(upperBound) <= 0;
	}

	int compare(const Time& other) const
	{
		int mySeconds = getSecondsFromMidnight();
		int otherSeconds = other.getSecondsFromMidnight();

		return mySeconds - otherSeconds;
	}

	Time getDiff(const Time& other) const
	{
		unsigned mySeconds = getSecondsFromMidnight();
		unsigned otherSeconds = other.getSecondsFromMidnight();

		size_t diff;

		if (mySeconds > otherSeconds)
			diff = mySeconds - otherSeconds;
		else
			diff = otherSeconds - mySeconds;

		return Time(diff);
	}

};


int main()
{
	Time t(12, 4, 55);

	t.print();

}
