#include "SetByString.h"

void SetByString::extractNumbersFromString()
{
    removeAll();
    std::stringstream myStream(str);

    while (!myStream.eof())
    {
        unsigned current;
        myStream >> current;
        addNumber(current);
    }
}

void SetByString::copyFrom(const SetByString& other)
{
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

void SetByString::free()
{
    delete[] str;
    str = nullptr;
}
SetByString::SetByString(unsigned n, const char* data) : SetOfNumbers(n)
{
    str = new char[strlen(data) + 1];
    strcpy(str, data);
    extractNumbersFromString();
}

SetByString::SetByString(const SetByString& other) : SetOfNumbers(other)
{
    copyFrom(other);
}
void SetByString::moveFrom(SetByString&& other)
{
    str = other.str;
    other.str = nullptr;
}


SetByString::SetByString(SetByString&& other) : SetOfNumbers(std::move(other))
{
    moveFrom(std::move(other));
}

SetByString& SetByString::operator=(SetByString&& other)
{
    if (this != &other)
    {
        SetOfNumbers::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

SetByString& SetByString::operator=(const SetByString& other)
{
    if (this != &other)
    {
        SetOfNumbers::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

SetByString::~SetByString()
{
    free();
}// извиква се дестр на SetOfNumbers

bool SetByString::conatins(int i) const
{
    return SetOfNumbers::contains(i);
}
void SetByString::print() const
{
    SetOfNumbers::print();
}

void SetByString::setAt(unsigned ind, char ch)
{
    str[ind] = ch;
    extractNumbersFromString();
}
