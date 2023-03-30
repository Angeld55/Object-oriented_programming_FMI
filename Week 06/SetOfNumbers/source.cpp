// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <assert.h>
#include "SetOfNumbers.h"


int main()
{

    SetOfNumbers s(10);

    s.addNumber(4);
    s.addNumber(8);


    s.print();
    SetOfNumbers s2(10);

    s2.addNumber(1);
    s2.addNumber(4);
    s2.addNumber(9);

    s2.print();

    SetOfNumbers is = unionOfSets(s, s2);
    SetOfNumbers us = intersectionOfSets(s, s2);

    is.print();
    us.print();

}
