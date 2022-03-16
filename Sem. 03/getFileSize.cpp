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
	
			
	if(!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}
		
	
	std::cout << getFileSize(file) << " bytes" << std::endl;
	
	return 0;
}
