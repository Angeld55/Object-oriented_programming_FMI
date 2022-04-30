#pragma once
#include "MyString/MyString.h"


class StringPool
{
	MyString** data;
	size_t count;

	void copyFrom(const StringPool& other);
	void free();
	void resize(size_t newCount);

	int findWord(const MyString& str) const;

public:
	StringPool();

	StringPool(const StringPool& other);
	StringPool& operator=(const StringPool& other);
	
	StringPool& operator*=(const MyString& word);
	StringPool& operator/=(const MyString& word);

	bool operator[](const MyString& str) const;

	friend std::ostream& operator<<(std::ostream&, const StringPool&);
	friend void operator>>(const MyString&, StringPool&);

	StringPool& operator+=(const StringPool& other);
	StringPool& operator-=(const StringPool& other);

	~StringPool();
};

StringPool operator+(const StringPool& lhs, const StringPool& rhs);
StringPool operator-(const StringPool& lhs, const StringPool& rhs);
