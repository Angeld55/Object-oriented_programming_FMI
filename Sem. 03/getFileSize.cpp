#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

size_t getFileSize(std::ifstream& file)
{
	size_t currentPosition = file.tellg();

	file.seekg(0, ios::end);
	size_t result = file.tellg();
	file.seekg(currentPosition);
	return result;
}
int main()
{
	ifstream file("ddz.txt");
	std::cout << getFileSize(file) << std::endl;
}
