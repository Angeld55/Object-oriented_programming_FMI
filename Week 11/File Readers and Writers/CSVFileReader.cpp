#include "CSVFileReader.h"
#include <sstream>
#include <fstream>

int CSVFileReader::getCharCount(std::ifstream& ifs, char ch)
{
	size_t currPos = ifs.tellg();

	if (!ifs.is_open()) {
		return -1;
	}

	int count = 0;
	while (true) {
		char current = ifs.get();

		if (ifs.eof()) {
			break;
		}

		if (current == ch) {
			count++;
		}
	}

	ifs.clear();
	ifs.seekg(currPos);
	return count;
}

CSVFileReader::CSVFileReader(const MyString& filePath) : FileReader(filePath)
{

}

int* CSVFileReader::read(size_t& size) const
{
	std::ifstream inFile(filePath.c_str());

	if (!inFile.is_open()) {
		throw std::exception("Cannot open file");
	}

	size = getCharCount(inFile, ',') + 1;
	int* arr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		inFile >> arr[i];
		inFile.ignore();
	}
	inFile.close();
	return arr;
}
