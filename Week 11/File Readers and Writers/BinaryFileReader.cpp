#include "BinaryFileReader.h"
#include <fstream>


int BinaryFileReader::getFileSize(std::ifstream& ifs)
{
	int currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	int size = ifs.tellg();
	ifs.seekg(currPos);

	return size;
}

BinaryFileReader::BinaryFileReader(const MyString& filePath) : FileReader(filePath)
{
}

int* BinaryFileReader::read(size_t& size) const
{
	std::ifstream inFile(filePath.c_str(), std::ios::binary);

	if (!inFile.is_open()) {
		throw std::exception("Cannot open file");
	}

	size = getFileSize(inFile) / sizeof(int);
	int* arr = new int[size];

	inFile.read((char*)arr, size * sizeof(int));
	inFile.close();
	return arr;
}
