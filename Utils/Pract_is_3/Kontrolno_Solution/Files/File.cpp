#pragma once
#include "File.h"
#pragma warning (disable : 4996)


File::File(const char* filename) {
	strncpy(this->filename, filename, NAME_LEN);
}

const char* File::getName() const {
	return filename;
}

void File::printInDir(unsigned depth) const {
	for (int i = 0; i < depth; i++) {
		std::cout << "\t";
	}
	std::cout << filename << std::endl;
}
