#include <iostream>
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
    std::cout << unionExample.n;
}
