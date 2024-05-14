#pragma once
#include "FileReader.h"

class ArrFileReader : public FileReader
{
	static int getCharCount(std::ifstream& ifs, char ch);
public:
	ArrFileReader(const MyString& filePath);
	int* read(size_t& size) const override;
};

