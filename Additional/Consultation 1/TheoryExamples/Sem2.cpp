#include <fstream>
#include <iostream>

size_t getFileSize(std::ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

unsigned getCharCountFromFile(std::ifstream& in, char ch) {
	size_t currentPosition = in.tellg();
	in.seekg(0, std::ios::beg);

	if (!in.is_open()) {
		return 0;
	}

	unsigned int count = 0;
	char current;
	while (true) {
		in.get(current); // current = in.get();
		if (in.eof()) {
			break;
		}

		if (current == ch) {
			count++;
		}
	}

	in.clear();
	in.seekg(currentPosition);
	return count;
}

unsigned getLinesCount(const char* fileName) {
	std::ifstream in(fileName);

	if (!in.is_open()) {
		return 0;
	}

	return getCharCountFromFile(in, '\n') + 1;
}

int main3()
{
	std::cout << getLinesCount("file.txt");
	return 0;
}