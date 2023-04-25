#include <iostream>
#include <string>
#include "MyString.h"


void f(MyString str1)
{
	std::cout << str1;
}

void g(MyString&& str1)
{
	std::cout << str1;
}

int main()
{
	MyString test1("test1");
	f(std::move(test1));


	MyString test2("test2");
	g(std::move(test2));
}