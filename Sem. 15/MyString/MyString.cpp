#include "MyString.h"
#include <cstring>
#include <iostream>
#include <iomanip>

void MyString::copyFrom(const MyString& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	size = other.size;
}
void MyString::free()
{
	delete[] str;
}

MyString::MyString(const char* data)
{
	if(data == nullptr)
	{
		str = new char[1];
		str[0] = '\0';
		size = 0;
	}
	else
	{
		size = strlen(data);
		str = new char[size + 1];
		strcpy(str, data);
	}
}

size_t getNumSize(size_t num)
{
	size_t res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return res;
}
MyString::MyString(size_t n)
{
	int numSize = getNumSize(n);
	str = new char[numSize + 1];

	str[numSize] = '\0';

	for (size_t i = 0; i < numSize; i++, n /= 10)
		str[numSize - 1 - i] = (n % 10) + '0';
	size = numSize;
}

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}
MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
MyString::~MyString()
{
	free();
}


size_t MyString::getSize() const
{
	return size;
}
void MyString::concatFrom(const MyString& other)
{
	char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
	size = size + other.getSize();
}

const char* MyString::c_str() const
{
	return str;
}

MyString& MyString::operator+=(const MyString& other)
{
	concatFrom(other);
	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}

std::ostream& operator<<(std::ostream& stream, const MyString& str)
{
	stream << str.str;
	return stream;
}

std::istream& operator>>(std::istream& stream, MyString& str)
{
	delete[] str.str;
	char buff[1024];
	stream >>  std::setw(1024) >> buff;

	str.size = strlen(buff);
	str.str = new char[str.size + 1];
	strcpy(str.str, buff);

	return stream;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;

}
bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;

}

MyString::MyString(MyString&& otherString)
{
	str = otherString.str;
	size = otherString.size;
	otherString.str = nullptr;
}

MyString& MyString::operator=(MyString&& otherString)
{

	if (this != &otherString)
	{
		free();
		str = otherString.str;
		otherString.str = nullptr;
		size = otherString.size;
	}
	return *this;
}

MyString MyString::subString(size_t start, size_t end) const
{
	if (end < start || end >= size)
		throw std::logic_error("Invalid params");
	
	MyString result;
	delete[] result.str;

	result.str = new char[end - start + 2];
	for (int i = start; i <= end; i++)
		result.str[i - start] = str[i];


	result.str[(end - start) + 1] = '\0';
	result.size = end - start + 1;

	return result;
}

const char& MyString::operator[](size_t index) const
{
	if (index > size)
		throw std::out_of_range("Out of range!");
	return str[index];
}


char& MyString::operator[](size_t index)
{
	if (index > size)
		throw std::out_of_range("Out of range!");
	return str[index];
}