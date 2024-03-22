#include "HelperFunctions.h"
#include <cmath>

namespace 
{
    const size_t DIGITS_COUNT = 10;
}

bool HelperFunctions::isPrime(int num) 
{
    if (num < 2)
        return false;

    if (num == 2)
        return true;


    double sqrtN = sqrt(num);

    
    for (int i = 2; i <= sqrtN; i++) 
    {
        if (num % i == 0) 
            return false;
    }

    return true;
}

int HelperFunctions::reverseNumber(int num) 
{
    int res = 0;

    while (num != 0)
    {
        (res *= 10) += num % 10;
        num /= 10;
    }

    return res;
}

bool HelperFunctions::isPalindrome(int num) 
{
    return num == reverseNumber(num);
}

bool HelperFunctions::isPowOfTwo(int n) 
{
    if (n < 0) 
        return false;

    return n == 0 || (n & n - 1) == 0;
}

bool HelperFunctions::hasOnlyUniqueDigits(int num)
{
    bool flags[DIGITS_COUNT] = {};

    num = num > 0 ? num : -num;

    while (num != 0) 
    {
        int digit = num % 10;

        if (flags[digit]) 
            return false;

        flags[digit] = true;

        num /= 10;
    }

    return true;
}