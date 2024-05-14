#include "BinaryFileWriter.h"
#include <fstream>

BinaryFileWriter::BinaryFileWriter(const MyString& filePath) : FileWriter(filePath)
{
}

void BinaryFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream outFile(filePath.c_str(), std::ios::binary);

	if (!outFile.is_open()) {
		throw std::exception("Cannot open file");
	}

	outFile.write((const char*)arr, size * sizeof(int));
	outFile.close();
}
