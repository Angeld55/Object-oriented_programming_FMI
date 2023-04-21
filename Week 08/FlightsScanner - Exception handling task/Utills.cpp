#include <iostream>

//we don't make them static, because we want to use the in other cpp files.

bool isLower(char ch) { return ch >= 'a' && ch <= 'z'; }

bool isSymbol(char ch)
{
	return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}

void toUpper(char* str)
{
	if (str == nullptr)
		throw std::invalid_argument("The given string does not exist");

	static int diff = 'a' - 'A';
	while (*str)
	{
		if (!isSymbol(*str))
			throw std::bad_cast();
		if (isLower(*str))
			*str = *str - diff;
		str++;
	}
}

unsigned charToDigit(char ch)
{
	if (ch < '0' || ch > '9')
		throw std::bad_cast();

	return ch - '0';
}

unsigned convertToNumber(const char* str)
{
	if (!str)
		throw std::invalid_argument("The given string does not exist");

	unsigned result = 0;
	while (*str)
	{
		result *= 10;
		result += charToDigit(*str);
		str++;
	}
	return result;
}