#include "Time.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Time::Time(unsigned hours, unsigned mins, unsigned seconds)
{
    setHours(hours);
    setMins(mins);
    setSeconds(seconds);
}

unsigned Time::getHours() const
{
    return secondsFromMidnight / SECONDS_IN_HOURS;
}

unsigned Time::getMins() const
{
    return (secondsFromMidnight / SECONDS_IN_MINUTE) % 60;
}

unsigned Time::getSeconds() const
{
    return secondsFromMidnight % 60;
}

bool Time::setHours(unsigned hours)
{
    return validateAndSet(0, 23, hours, getHours(), SECONDS_IN_HOURS);
}

bool Time::setMins(unsigned mins)
{
    return validateAndSet(0, 59, mins, getMins(), SECONDS_IN_MINUTE);
}

bool Time::setSeconds(unsigned seconds)
{
    return validateAndSet(0, 59, seconds, getSeconds(), 1);
}

void Time::tick()
{
    ++secondsFromMidnight %= DAY_SECONDS;
}

void Time::serialize(std::ostream& os) const
{
    using namespace std;
    os << setw(2) << setfill('0') << getHours() << ":"
        << setw(2) << setfill('0') << getMins() << ":"
        << setw(2) << setfill('0') << getSeconds() << endl;
}

bool Time::validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier)
{
    if (newValue >= lowerBound && newValue <= upperBound)
    {
        (secondsFromMidnight -= (oldValue * multiplier)) += (newValue * multiplier);
        return true;
    }
    else
        return false;
}


int compareTimes(const Time& lhs, const Time& rhs)
{
    //we don't have access to the secondsFromMidnight
    // and we don't know what 'static' and 'friend' is at this point of the course.

    if (lhs.getHours() == lhs.getHours())
    {
        if (lhs.getMins() == rhs.getMins())
            return lhs.getSeconds() - rhs.getSeconds();
        else
            return lhs.getMins() - rhs.getMins();
    }
    else
        return lhs.getHours() - rhs.getHours();


}