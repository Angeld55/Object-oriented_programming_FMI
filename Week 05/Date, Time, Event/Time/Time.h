#pragma once

#include <iostream>
#include <iomanip>

constexpr unsigned SECONDS_IN_HOURS = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;

class Time
{
private:
    unsigned secondsFromMidnight = 0;

    bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier);

public:
    Time() = default;
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
int compareTimes(const Time& lhs, const Time& rhs);