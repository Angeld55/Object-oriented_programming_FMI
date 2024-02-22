#include <iostream>

bool isDigit(char ch) {return ch >= '0' && ch <= '9';}
int convertCharToNumber(char ch){ return ch - '0'; }

unsigned convertStringToNumber(const char* str)
{
    if(!str)
        return 0;

    unsigned num = 0;
    while(*str)
    {
        if(!isDigit(*str))
            return 0; //error
            
        (num *= 10) += convertCharToNumber(*str); //concat digit at back
        
        str++;
    }
    return num;
}

int main()
{
    std::cout << convertStringToNumber("1234");
    return 0;
}
