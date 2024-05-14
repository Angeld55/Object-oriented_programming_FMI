#pragma once
#include "MyString.h"
class FileWriter
{
protected:
	MyString filePath;
public:
	FileWriter(const MyString& filePath);
	virtual void write(const int* arr, size_t size) const = 0;

	virtual ~FileWriter() = default;
};

