#include <fstream>

static bool isValidSymbol(unsigned char ch)
{
    return ch >= 32;
}
static unsigned char* createAndFillByteArray(size_t destSize, const unsigned char* source, size_t sourceSize)
{
    unsigned char* dest = new unsigned char[destSize];
    //you could use a loop here.
    memcpy(dest, source, sourceSize); //NO STRCPY!!! This is not a null terminated string
    return dest;
}
static const char* getFileExtension(const char* str)
{
    while (*str && *str != '.') str++;
    return str + 1;
}

int getCharCount(std::ifstream& ifs, char ch) {

    if (!ifs.is_open()) {
        return -1;
    }

    int count = 0;
    while (true) {
        char current = ifs.get();

        if (ifs.eof()) {
            return count;
        }

        if (current == ch) {
            count++;
        }
    }
    return 0;
}

static size_t getFileSize(std::ifstream& file)
{
    size_t currentPos = file.tellg();
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(currentPos);
    return fileSize;
}
