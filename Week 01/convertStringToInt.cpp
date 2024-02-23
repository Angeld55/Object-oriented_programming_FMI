#include <iostream>

bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }
int convertCharToNumber(char ch) { return ch - '0'; }

enum class ErrorCode
{
    OK,
    NullptrGiven,
    WrongCharInString,
    EmptyString
};

struct ConvertResult
{
    ErrorCode errCode;
    unsigned result;
};

ConvertResult convertStringToNumber(const char* str)
{
    if (!str)
        return { ErrorCode::NullptrGiven, 0};

    unsigned num = 0;
    if(!*str)
        return { ErrorCode::EmptyString, num };

    while (*str)
    {
        if (!isDigit(*str))
            return { ErrorCode::WrongCharInString, 0 }; 
        (num *= 10) += convertCharToNumber(*str); 
        str++;
    }
    return { ErrorCode::OK, num };
}

int main()
{
    ConvertResult res = convertStringToNumber("12343");
    
    if(res.errCode == ErrorCode::OK)
    {
        std::cout << res.result << std::endl;
    }
    else
    {
        std::cout << "Error!" << std::endl;
    }
}
