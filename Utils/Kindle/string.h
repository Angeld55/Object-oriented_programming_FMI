#pragma once

#include <fstream>
#include <iostream>
class string
{
	char* str;
	size_t size;

	void copyFrom(const string& other);
	void free();

public:
	string();
	string(const char*);

	string(const string&);

	string(string&&); //move constructor that accepts rvalue;

	string& operator=(const string& other);
	string& operator=(string&& other);  //move op= that accepts rvalue;

	~string();

	size_t getSize() const;
	void concat(const string& other);

	const char* c_str() const;

	string& operator+=(const string& other);

	friend std::ostream& operator<<(std::ostream& stream, const string& str);
	friend std::istream& operator>>(std::istream& stream, string& str);
	void getLine(std::istream& out);
};

string operator+(const string& lhs, const string& rhs);

bool operator==(const string& lhs, const string& rhs);
bool operator<=(const string& lhs, const string& rhs);
bool operator<(const string& lhs, const string& rhs);