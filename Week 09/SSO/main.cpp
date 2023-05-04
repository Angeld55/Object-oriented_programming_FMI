#include <iostream>
#include "MyStringSso.h"

int main()
{
    MyString sts("ABC");

    std::cout << sts.c_str() << std::endl;
    
    sts+="xyz";

    std::cout << sts << " " << sts.length() << std::endl;;


    sts+="12345678987654321";
    
    std::cout << sts << " " << sts.length() << std::endl;
    
    MyString st1("a");
    MyString st2("bffffffffffffffffffffffffffffffff");
    
    MyString res = st1 + st2;
    
    std::cout <<res;

    
}


