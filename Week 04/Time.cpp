#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

constexpr unsigned SECONDS_IN_HOURS = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;
class Time
{
private:
	unsigned secondsFromMidnight;

	bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier)
	{

		if (newValue >= lowerBound && newValue <= upperBound)
		{
			(secondsFromMidnight -= (oldVlaue * multiplier)) += (newValue * multiplier);
			return true;
		}
		else
			return false;
	}


public:

	Time() : secondsFromMidnight(0)
	{

	}
	Time(unsigned hours, unsigned mins, unsigned seconds)
	{
		setHours(hours);
		setMins(mins);
		setSeconds(seconds);
	}

	unsigned getHours() const
	{
		return secondsFromMidnight / SECONDS_IN_HOURS;
	}

	unsigned getMins() const
	{
		return (secondsFromMidnight / 60) % 60;
	}

	unsigned getSeconds() const
	{
		return secondsFromMidnight % 60;
	}
	bool setHours(unsigned hours)
	{
		return validateAndSet(0, 23, hours, getHours(), SECONDS_IN_HOURS);
	}

	bool setMins(unsigned mins)
	{
		return validateAndSet(0, 59, mins, getMins(), SECONDS_IN_MINUTE);

	}
	bool setSeconds(unsigned seconds)
	{
		return validateAndSet(0, 59, seconds, getSeconds(), 1);
	}

	void tick()
	{
		++secondsFromMidnight %= DAY_SECONDS;
	}

	void serialize(std::ostream& os) const
	{
		os << setw(2) << setfill('0') << getHours() << ":" 
		   << setw(2) << setfill('0') << getMins() <<  ":" 
		   << setw(2) << setfill('0') << getSeconds() << std::endl;
	}


};

int main()
{
	Time t(1,22,33);

	t.setMins(30);
	t.setSeconds(0);
	
	t.serialize(cout);
	t.tick();
	t.serialize(cout);

}
