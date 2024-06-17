#include "TypeOneFunction.h"

TypeOneFunction::TypeOneFunction(int16_t n, std::istream& is) : size(n), undefValues(n)
{
    undefValues.readFromFile(is, n);
}


Pair TypeOneFunction::operator()(int32_t value) const
{
    for (unsigned i = 0; i < size; i++)
    {
        if (undefValues[i] == value)
        {
            return Pair{ false, 0};
        }
    }

    return Pair{ true, value };
}

