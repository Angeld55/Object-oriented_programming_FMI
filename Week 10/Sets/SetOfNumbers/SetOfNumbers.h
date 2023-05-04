#pragma once


class SetOfNumbers
{
    unsigned char* data;
    unsigned maxNumber;

    void copyFrom(const SetOfNumbers& other);
    void free();

    unsigned getBucketIndex(unsigned number) const;
    unsigned getBucketsCount() const;

    unsigned char getMask(unsigned number) const;
public:
    SetOfNumbers() = default;
    SetOfNumbers(unsigned n);

    SetOfNumbers(const SetOfNumbers& other);
    SetOfNumbers& operator=(const SetOfNumbers& other);
    ~SetOfNumbers();

    bool contains(unsigned number) const;

    bool addNumber(unsigned number);
    bool removeNumber(unsigned number);

    unsigned getMaxNumber() const;
    void print() const;

    void removeAll();

    friend SetOfNumbers unionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs);
    friend SetOfNumbers intersectionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs);
};
