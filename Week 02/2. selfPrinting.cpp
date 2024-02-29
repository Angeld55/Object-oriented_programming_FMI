#include <iostream>
#include <assert.h>
#include <fstream>

int main()
{
	std::ifstream ifs("selfPrinting.cpp");
	if (!ifs.is_open())
		return -1;

	while (!ifs.eof())
	{
		char buff[1024];
		ifs.getline(buff, 1024);
		std::cout << buff << std::endl;
	}
}
