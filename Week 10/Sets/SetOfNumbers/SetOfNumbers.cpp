#include "SetOfNumbers.h"
#include <iostream>
#include <assert.h>

SetOfNumbers unionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs)
{
    assert(lhs.maxNumber == rhs.maxNumber);

    SetOfNumbers result(lhs.maxNumber + 1);
    for (unsigned i = 0; i < lhs.getBucketsCount(); i++)
        result.data[i] = (lhs.data[i] | rhs.data[i]);

    return result;
}
SetOfNumbers intersectionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs)
{
    assert(lhs.maxNumber == rhs.maxNumber);

    SetOfNumbers result(lhs.maxNumber + 1); //creates the same number of buckets
    for (unsigned i = 0; i < lhs.getBucketsCount(); i++)
        result.data[i] = lhs.data[i] & rhs.data[i];

    return result;
}
//unify intersection and unin


SetOfNumbers::SetOfNumbers(const SetOfNumbers& other)
{
    copyFrom(other);
}
SetOfNumbers& SetOfNumbers::operator=(const SetOfNumbers& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
SetOfNumbers::~SetOfNumbers()
{
    free();
}

void SetOfNumbers::copyFrom(const SetOfNumbers& other)
{
    unsigned bucketsCount = other.getBucketsCount();
    data = new unsigned char[bucketsCount];
    for (unsigned i = 0; i < bucketsCount; i++)
        data[i] = other.data[i];

    maxNumber = other.maxNumber;
}

void SetOfNumbers::free()
{
    delete[] data;
}

unsigned SetOfNumbers::getBucketsCount() const
{
    return (maxNumber + 1) / 8 + 1;
}


SetOfNumbers::SetOfNumbers(unsigned n)
{
    data = new unsigned char[n / 8 + 1];
    for (unsigned i = 0; i < (n / 8 + 1); i++)
        data[i] = 0;
    maxNumber = n - 1;
}

unsigned SetOfNumbers::getBucketIndex(unsigned number) const
{
    return number / 8;
}

unsigned char SetOfNumbers::getMask(unsigned number) const
{
    unsigned indexInBucket = number % 8;

    char mask = 1;

    mask = mask << (7 - indexInBucket);
    return mask;
}

bool SetOfNumbers::contains(unsigned number) const
{
    unsigned buckedIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);

    return (mask & data[buckedIndex]);
}

bool SetOfNumbers::addNumber(unsigned number)
{
    if (number > maxNumber || contains(number))
        return false;
    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);

    data[bucketIndex] |= mask;

    return true;
}
bool SetOfNumbers::removeNumber(unsigned number)
{
    if (number > maxNumber || !contains(number))
        return false;
    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);

    data[bucketIndex] ^= mask;

    return true;
}

void SetOfNumbers::print() const
{
    std::cout << "{ ";
    unsigned current = 0;
    for (int i = 0; i < getBucketsCount(); i++)
    {
        for (unsigned char j = 128; j >= 1; j >>= 1) //128 is 2^7
        {
            if (data[i] & j)
                std::cout << current << " ";
            current++;
        }
    }
    std::cout << "} " << std::endl;
}

unsigned SetOfNumbers::getMaxNumber() const
{
    return maxNumber;
}

void SetOfNumbers::removeAll()
{
    for (int i = 0; i < getBucketsCount(); i++)
        data[i] = 0;
  
}
