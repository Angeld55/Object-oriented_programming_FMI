#pragma once


class MyString
{
	char* str;
	size_t size;

	void copyFrom(const MyString& other);
	void free();
public:
	MyString();
	MyString(const char*);

	MyString(const MyString&);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t getSize() const;
	void concat(const MyString& other);

	const char* c_str() const;
};
//MyString name = "sdfsdf"