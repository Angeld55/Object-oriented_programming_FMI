#pragma once
#include"vector.hpp"
#include"string.h"
#include<iostream>
#include"serialize.h"

const short MAX_LINES_IN_PAGE = 26;

class Page {
private:
	Vector<string> lines;

	void write(unsigned linesCount);
	void displayPage() const;

	void writeToFile(std::ofstream& outFile) const;
	void readFromFile(std::ifstream& inFile);

	friend class Book;
};

