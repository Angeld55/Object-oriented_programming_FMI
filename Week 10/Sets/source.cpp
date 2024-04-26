// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SetByCriteria/SetByCriteria.h"
#include "SetByString/SetByString.h"


int main()
{
    SetByString s(1000, "1 5 9");
    s.print();
    s.setAt(1, '0');
    s.print();
    

    SetByCriteria s2(11, [](unsigned i) {return i % 2 == 0; });

    s2.print();
}
