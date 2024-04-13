#pragma once

constexpr unsigned N = 100;

class MapKeys0toN
{
public:
    MapKeys0toN(unsigned nullValue);
    void add(unsigned key, unsigned value);
    bool contains(unsigned key) const;
    unsigned getValue(unsigned key) const;

private:
    unsigned _values[N];
    unsigned _nullValue;
};

