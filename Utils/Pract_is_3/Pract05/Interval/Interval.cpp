#include "Interval.h"
#include "HelperFunctions.h"

unsigned Interval::countCriteria(bool(*pred)(int)) const
{
    unsigned count = 0;
    for (int i = start; i <= end; i++)
    {
        if (pred(i))
            count++;
    }

    return count;
}

Interval::Interval(int start, int end)
{
    if (start <= end)
    {
        this->start = start;
        this->end = end;
    }
}

unsigned Interval::length() const
{
    return end - start + 1;
}

bool Interval::isInterval(int num) const
{
    return start <= num && num <= end;
}

unsigned Interval::countPrime() const
{
    return countCriteria(HelperFunctions::isPrime);
}

unsigned Interval::countPalindrome() const
{
    return countCriteria(HelperFunctions::isPalindrome);
}

unsigned Interval::countUniqueDigits() const
{
    return countCriteria(HelperFunctions::hasOnlyUniqueDigits);
}

bool Interval::isPowOfTwo() const
{
    return HelperFunctions::isPowOfTwo(start) && HelperFunctions::isPowOfTwo(end);
}

Interval Interval::intersect(const Interval& other) const
{
    int start = this->start > other.start ? other.start : this->start;
    int end = this->end < other.end ? other.end : this->end;
}

bool Interval::isSub(const Interval& other) const
{
    return start >= other.start && end <= other.end;
}
