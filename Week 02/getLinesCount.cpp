#include <iostream>
#include <fstream>

unsigned getCharCountFromFile(std::ifstream& ifs, char ch)
{
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open())
		return 0;

	unsigned int count = 0;

	while (true)
	{
		char current = ifs.get();
		if (ifs.eof())
			break;

		if (current == ch)
			count++;
	}

	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}
unsigned getLinesCount(const char* fileName)
{
	std::ifstream myFile(fileName);

	if (!myFile.is_open())
		return 0;

	return getCharCountFromFile(myFile, '\n') + 1;
}

int main()
{
	std::cout << getLinesCount("file.txt");
}

