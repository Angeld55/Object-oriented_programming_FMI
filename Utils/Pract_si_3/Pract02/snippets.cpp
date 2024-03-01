#include <iostream>
#include <fstream>
// Structs

struct Empty {

};

struct Test1 {
    int a;
};

struct Test2 {
    char* a;
    int* b;
};

struct Test3 {
    char a[3];
    short b;
    double c[2];
    char d;
};

struct Test4 {
    int a[3];
    short b;
    char c[];
};

struct A {
    int i;
    bool b;
    double d;
};

struct B {
    A obj;
    int c;
};

struct C {
    A objA;
    B objB;
};

//union

union {
    uint32_t n = 0;
    char arr[4];
} unionExample;

int main() {
    unionExample.n = 257;
    unionExample.arr[0] = 'a'; // 'a' = 97
    std::cout << unionExample.n << '\n';
//eofbit
    {
        std::ifstream ifs("numbers.txt");
        if (!ifs.is_open())
            std::cout << "The file is not opened." << '\n';
        else
            std::cout << "The file was opened successfully." << '\n';
        while (true)
        {
            int n;
            ifs >> n;
            if (ifs.eof())
                break;
        }
        std::cout << "Badbit:  " << ifs.bad() << "\nFailbit: " << ifs.fail() << "\nEofbit: " << ifs.eof() << "\nGoodbit: " << ifs.good() << '\n';
        ifs.clear();
        std::cout << "After ifs.clear():\n";
        std::cout << "Badbit:  " << ifs.bad() << "\nFailbit: " << ifs.fail() << "\nEofbit: " << ifs.eof() << "\nGoodbit: " << ifs.good() << '\n';
    }
//failbit
    {
        std::ifstream ifs2("notANumber.txt");
        if (!ifs2.is_open())
            std::cout << "The file is not opened." << '\n';
        else
            std::cout << "The file was opened successfully." << '\n';

        int num;
        ifs2 >> num;
        std::cout << "Badbit:  " << ifs2.bad() << "\nFailbit: " << ifs2.fail() << "\nEofbit: " << ifs2.eof() << "\nGoodbit: " << ifs2.good() << '\n';
    }
}
