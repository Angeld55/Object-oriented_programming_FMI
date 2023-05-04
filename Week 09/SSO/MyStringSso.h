#include <iostream>
#pragma once
class MyString
{
	static const short SSO_MAX_SIZE = sizeof(char*) + sizeof(size_t) - 1;

	union
	{
		struct
		{
			char* _data;
			size_t _size;
		};
		char ssoData[MyString::SSO_MAX_SIZE + 1]{ '\0' };
	};

	bool isSso() const;
	void move(MyString&& other);
	void copyFrom(const MyString& other);
	void free();

	explicit MyString(size_t size);

	void notUsingSso();
public:

	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	MyString& operator+=(const MyString& other);

	const char* c_str() const;
	size_t length() const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	~MyString();

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

std::ostream& operator<<(std::ostream& os, const MyString& obj);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);