#include "CSVFileWriter.h"
#include <fstream>

CSVFileWriter::CSVFileWriter(const MyString& filePath) : FileWriter(filePath)
{
}

void CSVFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream outFile(filePath.c_str());

	if (!outFile.is_open()) {
		throw std::exception("Cannot open file");
	}

	for (size_t i = 0; i < size; i++)
	{
		outFile << arr[i];
		if (i != size - 1) {
			outFile << ',';
		}
	}

	outFile.close();
}
