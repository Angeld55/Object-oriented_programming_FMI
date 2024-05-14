#pragma once
#include "MyString.h"

class FilePath
{
	MyString name;
	MyString extension;

public:
	FilePath(const MyString& fileName);
	const MyString& getName() const;
	const MyString& getExtension() const;
};

