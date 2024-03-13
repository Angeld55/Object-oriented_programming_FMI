#include <iostream>
#include <fstream>

bool copyTo(const char* fileNameSource, const char* fileNameDest)
{
	std::ifstream sourceStream(fileNameSource);

	if (!sourceStream.is_open())
		return false;

	std::ofstream destStream(fileNameDest);
	if (!destStream.is_open())
		return false;

	while (!sourceStream.eof())
	{
		char buff[1024];
		sourceStream.getline(buff, 1024);
		destStream << buff << std::endl;
	}
}
int main()
{
	std::cout << copyTo("file1.txt", "file2.txt");
}
