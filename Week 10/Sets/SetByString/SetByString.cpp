#include "SetByString.h"
#pragma warning (disable : 4996)
void SetByString::extractNumbersFromString()
{
    removeAll();
    std::stringstream myStream(str);

    while (!myStream.eof())
    {
        unsigned current;
        myStream >> current;
        add(current);
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
SetByString::SetByString(unsigned n, const char* data) : DynamicSet(n)
{
    str = new char[strlen(data) + 1];
    strcpy(str, data);
    extractNumbersFromString();
}

SetByString::SetByString(const SetByString& other) : DynamicSet(other)
{
    copyFrom(other);
}
void SetByString::moveFrom(SetByString&& other)
{
    str = other.str;
    other.str = nullptr;
}


SetByString::SetByString(SetByString&& other) : DynamicSet(std::move(other))
{
    moveFrom(std::move(other));
}

SetByString& SetByString::operator=(SetByString&& other)
{
    if (this != &other)
    {
        DynamicSet::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

SetByString& SetByString::operator=(const SetByString& other)
{
    if (this != &other)
    {
        DynamicSet::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

SetByString::~SetByString()
{
    free();
}// èçâèêâà ñå äåñòð íà SetOfNumbers

bool SetByString::contains(int i) const
{
    return DynamicSet::contains(i);
}
void SetByString::print() const
{
    DynamicSet::print();
}

void SetByString::setAt(unsigned ind, char ch)
{
    str[ind] = ch;
    extractNumbersFromString();
}
