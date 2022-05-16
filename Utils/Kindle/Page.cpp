#include "Page.h"

void Page::write(unsigned linesCount) {
	if (linesCount > MAX_LINES_IN_PAGE)
		linesCount = MAX_LINES_IN_PAGE;


	for (size_t i = 0; i < linesCount; i++) {
		std::cout << i + 1 << " ";
		lines.pushBack(string());

		lines[i].getLine(std::cin);
	}
}

void Page::displayPage() const {
	for (size_t i = 0; i < lines.getSize(); i++)
		std::cout << lines[i] << std::endl;
}

void Page::writeToFile(std::ofstream& outFile) const {
	int len = lines.getSize();
	outFile.write((const char*)&len, sizeof(len));

	for (size_t i = 0; i < len; i++)
		writeString(outFile, lines[i]);
}

void Page::readFromFile(std::ifstream& inFile) {
	int len = 0;
	inFile.read((char*)&len, sizeof(len));

	for (size_t i = 0; i < len; i++) {
		string s = readString(inFile);
		lines.pushBack(std::move(s));
	}
}
