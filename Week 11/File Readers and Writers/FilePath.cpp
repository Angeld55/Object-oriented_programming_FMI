#include "FilePath.h"
#include <sstream>

FilePath::FilePath(const MyString& fileName) 
{
	const char* beg = fileName.c_str();
	const char* end = fileName.c_str() + fileName.getSize();
	const char* iter = end;

	while (iter != beg && *iter != '.') {
		iter--;
	}
	
	this->name = fileName.substr(0, iter - beg);
	this->extension = fileName.substr(iter - beg, end - iter);
}

const MyString& FilePath::getName() const
{
	return name;
}

const MyString& FilePath::getExtension() const
{
	return extension;
}
