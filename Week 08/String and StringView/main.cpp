#include <iostream>
#include <string>
#include "MyString.h"
#include "StringView.h"

void printSubstring(const StringView& view)
{
	std::cout << view << std::endl;
}


int main()
{
	MyString str("Hello, ");
	MyString str2 = " ";
	MyString str3 = " friends";

	MyString result = str + str2 + str3;

	result += "!";

	std::cout << result << std::endl;
	std::cout << result.length() << std::endl;
	result[16] = '?';

	std::cout << result << std::endl;

	MyString questionMark = result.substr(16, 1);
	std::cout << questionMark << std::endl;
	std::cout << questionMark.length() << std::endl;

	printSubstring(StringView(result).substr(9, 8));
	
	MyString cmpTestStr1 = "Abc";
	MyString cmpTestStr2 = "Abd";

	std::cout << (cmpTestStr1 < cmpTestStr2) << std::endl;
	std::cout << (cmpTestStr1 <= cmpTestStr2) << std::endl;
	std::cout << (cmpTestStr1 > cmpTestStr2) << std::endl;
	std::cout << (cmpTestStr1 >= cmpTestStr2) << std::endl;
	std::cout << (cmpTestStr1 == cmpTestStr2) << std::endl;
	std::cout << (cmpTestStr1 != cmpTestStr2) << std::endl;


}