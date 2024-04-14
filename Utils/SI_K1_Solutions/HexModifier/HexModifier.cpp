#include "HexModifier.h"
#include <fstream>
#include <sstream>
#pragma warning(disable::4996)

namespace GlobalConstants
{
    constexpr size_t BUFFER_SIZE = 1024;
    constexpr size_t HEX_DATA_BUFFER_SIZE = 3;
    constexpr char SEPARATOR = '!';
}

namespace HexFunctions
{
    bool isHexDigit(char hexDigit)
    {
        return (hexDigit >= '0' && hexDigit <= '9') || (hexDigit >= 'A' && hexDigit <= 'F');
    }

    int hexDigitIndex(char hexDigit)
    {
        if (hexDigit >= '0' && hexDigit <= '9')
        {
            return hexDigit - '0';
        }

        if (hexDigit >= 'A' && hexDigit <= 'F')
        {
            return hexDigit - 'A' + 10;
        }

        return -1;
    }

    char toHexDigit(unsigned int number)
    {
        if (number >= 0 && number <= 9)
        {
            return '0' + number;
        }

        if (number >= 10 && number <= 15)
        {
            return 'A' + number - 10;
        }

        return '\0';
    }

    unsigned char dataStringToHex(const char* newByte)
    {
        if (newByte == nullptr || std::strlen(newByte) != 2)
        {
            return 0;
        }

        if (!isHexDigit(newByte[0]) || !isHexDigit((newByte[1])))
        {
            return 0;
        }

        return hexDigitIndex(newByte[0]) * 16 + hexDigitIndex(newByte[1]);
    }

    void printHex(std::ostream& os, unsigned char number)
    {
        os << toHexDigit(number / 16) << toHexDigit(number % 16);
    }
}

namespace FileUtilities
{
    size_t getFileSize(std::ifstream& file)
    {
        size_t currentPos = file.tellg();
        file.seekg(0, std::ios::end);
        size_t fileSize = file.tellg();
        file.seekg(currentPos);
        return fileSize;
    }

    unsigned getCharCountFromFile(std::istream& is, char ch)
    {
        size_t currentPosition = is.tellg();
        is.seekg(0, std::ios::beg);

        unsigned int count = 0;

        while (true)
        {
            char current = is.get();
            if (is.eof())
                break;

            if (current == ch)
                count++;
        }

        is.clear();
        is.seekg(currentPosition);
        return count;
    }
}


void HexModifier::free()
{
    delete[] destPath;
    delete[] data;
    destPath = nullptr;
    data = nullptr;
    dataSize = 0;
}

void HexModifier::copyFrom(const HexModifier& other)
{
    destPath = new char[strlen(other.destPath) + 1];
    std::strcpy(destPath, other.destPath);

    data = new uint8_t[other.dataSize];
    for (size_t i = 0; i < other.dataSize; i++)
        data[i] = other.data[i];
    dataSize = other.dataSize;
}

HexModifier::HexModifier(const char* srcPath) : HexModifier(srcPath, srcPath) { }

HexModifier::HexModifier(const char* srcPath, const char* destPath)
{
    if (destPath != nullptr)
    {
        this->destPath = new char[std::strlen(destPath) + 1];
        std::strcpy(this->destPath, destPath);
    }

    if (srcPath != nullptr)
    {
        std::ifstream ifs(srcPath, std::ios::binary);
        if (!ifs.is_open())
        {
            delete[] this->destPath;
            return;
        }

        dataSize = FileUtilities::getFileSize(ifs);
        data = new unsigned char[dataSize];
        ifs.read((char*)data, dataSize);
    }
}

HexModifier::HexModifier(const HexModifier& other)
{
    copyFrom(other);
}

HexModifier& HexModifier::operator=(const HexModifier& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

HexModifier::~HexModifier()
{
    save();
    free();
}

void HexModifier::changeByte(unsigned int index, const char* newByte)
{
    if (index >= dataSize)
    {
        return;
    }

    data[index] = HexFunctions::dataStringToHex(newByte);
    isChanged = true;
}

void HexModifier::save() const
{
    if (!isChanged)
    {
        return;
    }

    std::ofstream ofs(destPath, std::ios::binary);

    if (!ofs.is_open())
    {
        return;
    }

    ofs.write((const char*)data, dataSize);
    ofs.close();
    isChanged = false;
}

std::ostream& operator<<(std::ostream& os, const HexModifier& modifier)
{
    for (size_t i = 0; i < modifier.dataSize; ++i)
    {
        HexFunctions::printHex(os, modifier.data[i]);
        os << ' ';
    }

    return os << std::endl;
}

std::istream& operator>>(std::istream& is, HexModifier& modifier)
{
    char buffer[GlobalConstants::BUFFER_SIZE];
    is >> buffer;

    std::stringstream ss(buffer);

    modifier.dataSize = FileUtilities::getCharCountFromFile(ss, GlobalConstants::SEPARATOR) + 1;

    delete[] modifier.data;
    modifier.data = new unsigned char[modifier.dataSize];

    modifier.isChanged = true;

    unsigned int index = 0;
    char dataBuffer[GlobalConstants::HEX_DATA_BUFFER_SIZE];
    while (!ss.eof())
    {
        ss.getline(dataBuffer, GlobalConstants::HEX_DATA_BUFFER_SIZE, GlobalConstants::SEPARATOR);
        modifier.changeByte(index, dataBuffer);
        index++;
    }

    return is;
}
