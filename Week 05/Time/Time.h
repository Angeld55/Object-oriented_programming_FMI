#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

class Time
{
private:
    unsigned secondsFromMidnight;

    bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier);

public:
    static constexpr unsigned SECONDS_IN_HOURS = 3600;
    static constexpr unsigned SECONDS_IN_MINUTE = 60;
    static constexpr unsigned DAY_SECONDS = 24 * 3600;

    Time();
    Time(unsigned hours, unsigned mins, unsigned seconds);

    unsigned getHours() const;
    unsigned getMins() const;
    unsigned getSeconds() const;
    bool setHours(unsigned hours);
    bool setMins(unsigned mins);
    bool setSeconds(unsigned seconds);
    void tick();
    void serialize(std::ostream& os) const;
};