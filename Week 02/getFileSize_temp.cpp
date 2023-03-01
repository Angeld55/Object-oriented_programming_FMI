#include <iostream>
#include <fstream>
#include <assert.h>

size_t getFileSize(const char* name)
{
	std::ifstream file(name);
	if (!file.is_open())
		return 0;
	
	file.seekg(0, std::ios::end);
	size_t currentPos = file.tellg();
	file.close();
	return currentPos;
}

int main()
{
	std::cout << (getFileSize("test.txt"));
	
}
