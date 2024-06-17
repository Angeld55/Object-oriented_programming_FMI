#pragma once
#include "File.h"

const unsigned CONTENT_LENGTH = 1024 + 1;

class TextFile : public File {
	char content[CONTENT_LENGTH] {0};
public:
	TextFile(const char* filename);
	TextFile(const char* filename, const char* content);

	File* clone() const override;

	void printContent() const override;

	const char* getContent() const;
};

