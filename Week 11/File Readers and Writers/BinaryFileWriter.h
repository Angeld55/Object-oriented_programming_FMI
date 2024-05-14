#pragma once
#include "FileWriter.h"

class BinaryFileWriter : public FileWriter
{
public:
	BinaryFileWriter(const MyString& filePath);
	void write(const int* arr, size_t size) const override;
};
