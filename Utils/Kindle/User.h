#pragma once
#include"string.h"
#include"vector.hpp"
#include"Book.h"
#include"serialize.h"

class User {
private:
	string name;
	string password;
	Vector<size_t> indexesOfBooksRead;
	Vector<size_t> indexesOfBooksWritten;

	friend class Kindle;
public:
	User() {}
	User(const string& pName, const string& pPassword);

	void writeToFile(std::ofstream& outFile) const;
	void readFromFile(std::ifstream& inFile);
};

