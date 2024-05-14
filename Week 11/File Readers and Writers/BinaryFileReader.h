#pragma once
#include "FileReader.h"
class BinaryFileReader : public FileReader
{
	static int getFileSize(std::ifstream& ifs);
public:
	BinaryFileReader(const MyString& filePath);
	int* read(size_t& size) const override;
};

