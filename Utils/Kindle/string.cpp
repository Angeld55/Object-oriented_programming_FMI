#include "string.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

void string::copyFrom(const string& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	size = other.size;
}
void string::free()
{
	delete[] str;
}

string::string()
{
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

string::string(const char* data)
{
	if (data == nullptr)
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

string::string(const string& other)
{
	copyFrom(other);
}
string& string::operator=(const string& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
string::~string()
{
	free();
}


size_t string::getSize() const
{
	return size;
}
void string::concat(const string& other)
{
	char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
	size = size + other.getSize();
}

const char* string::c_str() const
{
	return str;
}

string& string::operator+=(const string& other)
{
	concat(other);
	return *this;
}

void string::getLine(std::istream& outFile) 
{
	delete[] str;
	char buff[1024];

	outFile.getline(buff, 1024, '\n');
	size_t len = strlen(buff);
	str = new char[len + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = buff[i];
	str[len] = '\0';
	size = len;
}

string operator+(const string& lhs, const string& rhs)
{
	string copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}

std::ostream& operator<<(std::ostream& stream, const string& str)
{
	stream << str.str;
	return stream;
}

std::istream& operator>>(std::istream& stream, string& str)
{
	delete[] str.str;
	char buff[1024];
	stream >> buff;

	str.size = strlen(buff);
	str.str = new char[str.size + 1];
	strcpy(str.str, buff);

	return stream;
}

bool operator==(const string& lhs, const string& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator<=(const string& lhs, const string& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;

}
bool operator<(const string& lhs, const string& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;

}

string::string(string&& otherString)
{
	str = otherString.str;
	size = otherString.size;
	otherString.str = nullptr;
}

string& string::operator=(string&& otherString)
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