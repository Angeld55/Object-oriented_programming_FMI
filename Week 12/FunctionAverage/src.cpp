#include <iostream>
#include <fstream>
#include "FunctionAverage.hpp"

class NumberInFile
{
private:
    int* data = nullptr;
    size_t size = 0;
    bool loaded = false;

    static unsigned getFileSize(std::ifstream& ifs)
    {
        size_t currentPos = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t fileSize = ifs.tellg();
        ifs.seekg(currentPos);
        return fileSize;
    }

    void load(const char* filePath)
    {
        std::ifstream ifs(filePath);
        if(!ifs.is_open())
            return;

        size = getFileSize(ifs) / sizeof(int);
        data = new int[size]{};
        ifs.read((char*)data, size * sizeof(int));
        loaded = true;
    }

    void copyFrom(const NumberInFile& other)
    {
        size = other.size;
        data = new int[size]{};
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    void free()
    {
        delete[] data;
    }

public:
    NumberInFile(const char* filePath) 
    {
        load(filePath);
    }

    int operator()(int x) const
    {
        for (size_t i = 0; i < size; i++)
        {
            if(x == data[i])
            {
                return x;
            }
        }
        return 0;
    }

    bool good() const
    {
        return loaded;
    }

    NumberInFile(const NumberInFile& other) 
    {
        copyFrom(other);
    }

    NumberInFile& operator=(const NumberInFile& other) 
    {
        if(this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~NumberInFile()
    {
        free();
    }
};



int main()
{
    char filePath[1024]{};
    std::cin.getline(filePath, 1024);

    NumberInFile func(filePath);
    if(func.good())
    {
        std::cout << "Loaded!" << std::endl;
    }
    else
    {
        std::cout << "Invalid file path";
        return 1;
    }

    IntFunctionAverage<NumberInFile, int (*)(int)> f(func, [](int x) -> int { return x; });

    while(true)
    {
        int num = 0;
        std::cin >> num;
        std::cout << "Average: " << f.average(num) << std::endl;
    }
}