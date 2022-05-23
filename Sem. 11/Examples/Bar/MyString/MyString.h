#pragma once

#include <fstream>
class MyString
{
	char* str;
	size_t size;

	void copyFrom(const MyString& other);
	void free();

	void concatFrom(const MyString& other);

public:
	MyString();
	MyString(const char*);
	MyString(size_t n); //convert constructor

	MyString(const MyString&);

	MyString(MyString&&); //move constructor that accepts rvalue;

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);  //move op= that accepts rvalue;

	~MyString();

	size_t getSize() const;

	const char* c_str() const;

	MyString& operator+=(const MyString& other);

	friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
	friend std::istream& operator>>(std::istream& stream, MyString& str);

};

MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
