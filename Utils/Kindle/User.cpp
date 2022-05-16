#include "User.h"

User::User(const string& pName, const string& pPassword) {
	name = pName;
	password = pPassword;
}

void User::writeToFile(std::ofstream& outFile) const {
	writeString(outFile, name);
	writeString(outFile, password);

	writeVector(outFile, indexesOfBooksRead);
	writeVector(outFile, indexesOfBooksWritten);
}

void User::readFromFile(std::ifstream& inFile) {
	name = readString(inFile);
	password = readString(inFile);

	indexesOfBooksRead = readVector(inFile);
	indexesOfBooksWritten = readVector(inFile);
}
