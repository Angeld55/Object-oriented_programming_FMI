#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

const size_t capacity = 1024;

size_t getTextFileLength(const char* fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
		return 0;

	size_t count = 0; 
	while (!file.eof()) // there are better ways  to do that
	{
		file.get();
		count++;
	}

	return count - 1;
}
int main()
{	
	std::cout << getTextFileLength("test.txt");
}
