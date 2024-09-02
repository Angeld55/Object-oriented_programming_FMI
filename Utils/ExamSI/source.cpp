#include <iostream>
#include <fstream>
#include "Utils.h"
#pragma warning (disable : 4996)

class HexArray
{
public:
    HexArray(const unsigned char* initData, size_t initDataSize)
    {
        data = createAndFillByteArray(initDataSize, initData, initDataSize);
        size = initDataSize;
    }
    
    HexArray(const HexArray& other) {
        copyFrom(other);
    }

    HexArray& operator=(const HexArray& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    HexArray(HexArray&& other) noexcept {
        moveFrom(std::move(other));
    }

    HexArray& operator=(HexArray&& other) noexcept {
        if (this != &other) {
            free();
            moveFrom(std::move(other));
        }
    }

    ~HexArray() {
        free();
    }

    friend std::ostream& operator<<(std::ostream& os, const HexArray& arr)
    {
        for (int i = 0; i < arr.size; i++) 
        {
            if (isValidSymbol(arr.data[i]))
            {
                os << std::hex << arr.data[i] << " ";
            }
            else
            {
                os << '.' << " ";
            }
        }
        os << std::endl;
        for (int i = 0; i < arr.size; i++)
            os << std::hex << (int)arr.data[i] << " ";

        return os;
    }
    
    template <class T>
    friend void operator>>(const T& toSerialize, HexArray& arr)
    {
        unsigned char* newData = createAndFillByteArray(arr.size + sizeof(T), arr.data, arr.size);
        memcpy(newData + arr.getSize(), reinterpret_cast<const unsigned char*>(&toSerialize), sizeof(T));
        arr.size += sizeof(T);
        delete[] arr.data;
        arr.data = newData;
    }
    const unsigned char* c_str() const
    {
        return data;
    }
    unsigned getSize() const
    {
        return size;
    }
private:
    unsigned char* data;
    size_t size;

    void copyFrom(const HexArray& other) {
        size = other.size;
        data = createAndFillByteArray(size, other.data, other.size);
    }

    void moveFrom(HexArray&& other) {
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    void free() {
        delete[] data;
    }
};

class HexArrayView
{
    const unsigned char* _begin;
    const unsigned char* _end; //1 element after the final byte;

public:
    HexArrayView(const HexArray& arr) : _begin(arr.c_str()), _end(arr.c_str() + arr.getSize()) {}
    HexArrayView(const unsigned char* begin, const unsigned char* end) : _begin(begin), _end(end) {}
    size_t length() const
    {
        return _end - _begin;
    }
    unsigned char operator[](size_t ind) const
    {
        return _begin[ind];
    }

    HexArrayView substr(size_t from, size_t length) const
    {
        return HexArrayView(_begin + from, _begin + from + length);
    }
    friend std::ostream& operator<<(std::ostream&, const HexArrayView& strView)
    {
        const unsigned char* iter = strView._begin;
        while (iter != strView._end)
        {
            std::cout << std::hex << iter++;
        }
    }
};

class Serializator
{
protected:
    char fileName[128];
    const HexArray& arr;
public:
    Serializator(const char* str, const HexArray& arr) : arr(arr) { strcpy(fileName, str); }
    virtual void serialize() = 0;
    virtual Serializator* clone() const = 0;
    virtual ~Serializator() = default;
};

class BinarySerializator : public Serializator
{
public:
    BinarySerializator(const char* str, const HexArray& arr) : Serializator(str, arr) {}
    virtual void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary);
        ofs.write((const char*)arr.c_str(), arr.getSize());
    }
    virtual Serializator* clone() const override {
        return new BinarySerializator(*this);
    }
};

class TxtHexSerializator : public Serializator
{
public:
    TxtHexSerializator(const char* str, const HexArray& arr) : Serializator(str, arr) {}
    virtual void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary);
        for (int i = 0; i < arr.getSize(); i++)
            ofs << std::hex << arr.c_str()[i] << " ";
    }
    virtual Serializator* clone() const override {
        return new TxtHexSerializator(*this);
    }
};
class TxtDecimalSerializator : public Serializator
{
public:
    TxtDecimalSerializator(const char* str, const HexArray& arr) : Serializator(str, arr) {}

    virtual void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary);
        for (int i = 0; i < arr.getSize(); i++)
            ofs << arr.c_str()[i] << " ";
    }

    virtual Serializator* clone() const override {
        return new TxtDecimalSerializator(*this);
    }
};

Serializator* serializatorFactory(const HexArray& arr, const char* str);

class RecSerializator : public Serializator
{
public:
    RecSerializator(const char* str, const HexArray& arr) : Serializator(str, arr)
    {
        std::ifstream ifs(str);
        char recFileName[1024];
        ifs >> recFileName;
        ser = serializatorFactory(arr, recFileName);
    }
    virtual void serialize() override
    {
        std::ofstream ofs(fileName, std::ios::binary | std::ios::trunc); //to trunc the file.
        ser->serialize();
    }
    virtual Serializator* clone() const override {
        return new RecSerializator(*this);
    }

    RecSerializator(const RecSerializator& other) : Serializator(other)
    {
        ser = ser->clone();
    }
    ~RecSerializator()
    {
        delete ser;
    }
private:
    Serializator* ser;

};

class Deserializator
{
protected:
    char fileName[127];
public:
    Deserializator(const char* str) { strcpy(fileName, str); }
    virtual HexArray deserialize() const = 0;
    virtual ~Deserializator() = default;
};

class BinaryDeserializator : public Deserializator
{
public:
    BinaryDeserializator(const char* str) : Deserializator(str) {}

    HexArray deserialize() const override
    {
        std::ifstream ifs(fileName);
        size_t size = getFileSize(ifs);
        unsigned char* data = new unsigned char[size];
        ifs.read((char*)data, size);
        return HexArray(data, size);
    }
};

class TxtHexDeserializator : public Deserializator
{
public:
    TxtHexDeserializator(const char* str) : Deserializator(str) {}

    HexArray deserialize() const override
    {
        std::ifstream ifs(fileName);
        unsigned size = getCharCount(ifs, ' ') + 1;
        unsigned char* res = new unsigned char[size];
        for (int i = 0; i < size; i++)
        {
            int tempByte;  //hex does not work for chars ?? only ints?
            ifs >> std::hex >> tempByte; //works for newlines and spaces!!
            res[i] = tempByte;
        }
        return HexArray(res, size);
    }
};
class TxtDecimalDeserializator : public Deserializator
{
public:
    TxtDecimalDeserializator(const char* str) : Deserializator(str) {}
    HexArray deserialize() const override
    {
        std::ifstream ifs(fileName);
        unsigned size = getCharCount(ifs, '\n') + 1;
        unsigned char* res = new unsigned char[size];
        for (int i = 0; i < size; i++)
        {
            int tempByte;
            ifs >> tempByte;
            res[i] = tempByte;
        }
        return HexArray(res, size);
    }
};

Serializator* serializatorFactory(const HexArray& arr, const char* str)
{
    const char* extension = getFileExtension(str);
    if (strcmp(extension, ".dat"))
        return new BinarySerializator(str, arr);
    if (strcmp(extension, ".txtHex"))
        return new TxtHexSerializator(str, arr);
    if (strcmp(extension, ".dat"))
        return new TxtDecimalSerializator(str, arr);
    if (strcmp(extension, ".rec"))
        return new RecSerializator(str, arr);
    return nullptr;
}

Deserializator* deserializatorFactory(const char* str)
{
    const char* extension = getFileExtension(str);
    if (strcmp(extension, ".dat"))
        return new BinaryDeserializator(str);
    if (strcmp(extension, ".txtHex"))
        return new TxtHexDeserializator(str);
    if (strcmp(extension, ".dat"))
        return new TxtDecimalDeserializator(str);
    return nullptr;
}



int main()
{
    char temp[1024], inputName[128], outputName[128];
    std::cin >> inputName;
    Deserializator* des = deserializatorFactory(inputName);
    std::cin >> temp; //read
    HexArray ha = des->deserialize();
    int n;
    std::cin >> n;
    n >> ha;
    std::cin >> outputName;
    Serializator* ser = serializatorFactory(ha, outputName);
    std::cin >> temp; //write;
    ser->serialize();
    delete ser;
    delete des;
}
