#include "MyString.h"

int main()
{
	MyString test = "test str";

	std::cout << test << " ";
	std::cout << test.getSize() << " " << test.getCapacity() << std::endl;
	
	MyString test2;
	std::cin >> test2;

	MyString test3 = test + test2;
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	
	test3 += test3;
	std::cout << test3;

}
