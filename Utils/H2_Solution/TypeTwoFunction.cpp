#include "TypeTwoFunction.h"

TypeTwoFunction::TypeTwoFunction(int16_t n, std::istream& is) : size(n), oneValues(n)
{
    oneValues.readFromFile(is, n);
}


Pair TypeTwoFunction::operator()(int32_t value) const
{
    for (unsigned i = 0; i < size; i++)
    {
        if (oneValues[i] == value)
        {
            return Pair{ true, 1 };
        }
    }

    return Pair{ true, 0 };
}

