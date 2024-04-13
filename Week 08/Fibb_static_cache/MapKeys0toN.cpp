#include "MapKeys0toN.h"

MapKeys0toN::MapKeys0toN(unsigned nullValue)
{
    for (int i = 0; i < N; i++)
        _values[i] = nullValue;
    _nullValue = nullValue;
}

void MapKeys0toN::add(unsigned key, unsigned value)
{
    if (value == _nullValue)
        return;

    _values[key] = value;
}

bool MapKeys0toN::contains(unsigned key) const
{
    return _values[key] != _nullValue;
}

unsigned MapKeys0toN::getValue(unsigned key) const
{
    if (!contains(key))
        throw "Error";
    return _values[key];
}
