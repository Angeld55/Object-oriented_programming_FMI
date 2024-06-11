#pragma once
#include <iostream>

const int NAME_LEN = 32 + 1;
class File {
	char filename[NAME_LEN];
public:
	File(const char* filename);

	//	!!!
	virtual File* clone() const = 0;
	virtual ~File() = default;

	virtual void printContent() const = 0;
	virtual void printInDir(unsigned depth) const;

	const char* getName() const;
};