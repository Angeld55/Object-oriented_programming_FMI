#pragma once
#include<fstream>
#include "Timestamp.h"
const int MAX_FILE_SIZE = 100;
class LogFile {
private:
	size_t size;
	Timestamp data[MAX_FILE_SIZE];

	void readTime(std::ifstream& inFile, Timestamp& obj) const;

public:
	LogFile();

	LogFile(const char* filePath);

	int getLoginsCountAfterHour(short hours, short minutes, short seconds) const;

	int getLoginsCountBetweenHours(short h1, short m1, short s1, short h2, short m2, short s2) const;

	int getLongestActivePeriod() const;

	bool loggedInHour(int hour) const;
};