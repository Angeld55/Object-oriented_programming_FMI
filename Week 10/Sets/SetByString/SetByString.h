#pragma once
#include "../DynamicSet/DynamicSet.h"
#include <sstream>

class SetByString : private DynamicSet
{
    char* str;

    void extractNumbersFromString();
    void copyFrom(const SetByString& other);
    void free();

    void moveFrom(SetByString&& other);

public:
    SetByString(unsigned n, const char* data);
    SetByString(const SetByString& other);
    SetByString(SetByString&& other);
    SetByString& operator=(SetByString&& other);
    SetByString& operator=(const SetByString& other);
    ~SetByString();

    bool contains(int i) const;
    void print() const;
    void setAt(unsigned ind, char ch);
};
