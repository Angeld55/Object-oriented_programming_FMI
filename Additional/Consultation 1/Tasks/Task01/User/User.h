#pragma once

#include <fstream>

class User {
private:
	char* userName = nullptr;
	char* password = nullptr;
	mutable size_t accessCounter = 0;

	void copyUserName(const char* userName);
	void copyPassword(const char* password);
    
public:
	User() = default;
	User(const char* userName, const char* password);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	const char* getUserName() const;
	size_t getAccessCounter() const;
	void setUserName(const char* userName);
	void setPassword(const char* password);

	void writeToFile(std::ofstream& out) const;
	void readFromFile(std::ifstream& in);

private:
	void free();
	void copyFrom(const User& other);
};