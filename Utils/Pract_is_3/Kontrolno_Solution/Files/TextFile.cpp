#include "TextFile.h"
#pragma warning (disable : 4996)


TextFile::TextFile(const char* filename) : File(filename) {}
TextFile::TextFile(const char* filename, const char* content) : File(filename) {
	strncpy(this->content, content, CONTENT_LENGTH);
}

File* TextFile::clone() const {
	return new TextFile(*this);
}

void TextFile::printContent() const {
	std::cout << getName() << std::endl << "-----------" << std::endl << content << std::endl;
}

const char* TextFile::getContent() const {
	return content;
}