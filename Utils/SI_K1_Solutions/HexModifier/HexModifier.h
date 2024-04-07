#pragma once
#include <iostream>

class HexModifier
{
    char* destPath = nullptr;
    unsigned char* data = nullptr;
    size_t dataSize = 0;

    mutable bool isChanged = false;

    void free();
    void copyFrom(const HexModifier& other);
public:
    HexModifier(const char* srcPath);
    HexModifier(const char* srcPath, const char* destPath);

    HexModifier(const HexModifier& other);
    HexModifier& operator=(const HexModifier& other);
    ~HexModifier();

    void changeByte(unsigned int index, const char* newByte);
    void save() const;

    friend std::ostream& operator<<(std::ostream& os, const HexModifier& modifier);
    friend std::istream& operator>>(std::istream& is, HexModifier& modifier);
};