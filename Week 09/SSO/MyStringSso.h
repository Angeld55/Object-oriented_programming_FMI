#include <iostream>
#pragma once
class MyString
{
	union 
	{
		struct
		{
			char* _data;
			size_t _size ;
		};
		char ssoData[sizeof(_data) + sizeof(_size)]{'\0'};
	};
	
	bool isSso() const;
	void copyFrom(const MyString& data);
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

MyString operator+(const MyString& lhs, const MyString& rhs);