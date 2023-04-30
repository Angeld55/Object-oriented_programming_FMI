#include <iostream>
#include "SortedStringPool.h"


int main()
{

	SortedStringPool str;

	str.addString("bbb");
	str.printAll();

	str.addString("aa");
	str.printAll();

	str.addString("cccc");
	str.printAll();

	str.addString("bbb");

	str.printAll();

	SortedStringPool str2 = str;

	str.removeAtIndex(1);

	str.printAll();
	str2.printAll();

	std::cout << str.contains("aa");
	
}