#include "MyStringSso.h"
#include <cstring>

#pragma warning (disable : 4996)

MyString::MyString() : MyString("") { }

MyString::MyString(size_t size)
{
	_data = new char[size + 1];
	this->_size = size;
}
MyString::MyString(const char* data)
{
	size_t currentSize = strlen(data);

	if (currentSize <= MyString::SSO_MAX_SIZE) //SSO
	{
		ssoData[MyString::SSO_MAX_SIZE] = MyString::SSO_MAX_SIZE - currentSize;
		strcpy(ssoData, data);
	}
	else
	{
		_size = currentSize;
		_data = new char[_size + 1];
		strcpy(_data, data);
		notUsingSso();
	}
}
void MyString::notUsingSso()
{
	ssoData[MyString::SSO_MAX_SIZE] |= (1 << 7);
}

MyString::MyString(MyString&& other) noexcept
{
	move(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
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

void MyString::move(MyString&& other) {
	_data = other._data;
	_size = other._size;
	
	if (!other.isSso())
	{
		other._data = nullptr;
		notUsingSso();
	}
}

void MyString::free()
{
	if (!isSso())
		delete[] _data;
	_data = nullptr;
}
MyString::~MyString()
{
	free();
}

bool MyString::isSso() const
{
	return (ssoData[MyString::SSO_MAX_SIZE] & (1 << 7)) == 0;
}

const char* MyString::c_str() const
{
	return isSso() ? ssoData : _data;
}

size_t MyString::length() const
{
	if (isSso())
	{
		return MyString::SSO_MAX_SIZE - ssoData[MyString::SSO_MAX_SIZE];
	}
	else
	{
		size_t realSize = _size;
		size_t mask = 1;
		mask = ~(mask << (sizeof(_size) * 8 - 1)); //we remove the bit of the size that shows us that SSO is not applied.
		return realSize & mask;
	}
}

void MyString::copyFrom(const MyString& other)
{
	if (!other.isSso())
	{
		_data = new char[other.length() + 1];
		strcpy(_data, other._data);
		_size = other._size;
	}
	else
	{
		strcpy(ssoData, other.ssoData);
		ssoData[MyString::SSO_MAX_SIZE] = other.ssoData[MyString::SSO_MAX_SIZE]; //copy the size
	}
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t newStrSize = length() + other.length();

	if (newStrSize <= MyString::SSO_MAX_SIZE)
	{ //sso is aplied in the current object
		strcat(ssoData, other.ssoData);
		ssoData[MyString::SSO_MAX_SIZE] = MyString::SSO_MAX_SIZE - newStrSize;
	}
	else
	{
		char* newData = new char[newStrSize + 1] {'\0'};

		strcpy(newData, c_str());
		strcat(newData, other.c_str());

		if (!isSso())
			delete[] _data;
		_data = newData;
		_size = newStrSize;
		notUsingSso();
	}

	return *this;
}


char& MyString::operator[](size_t index)
{
	return isSso() ? ssoData[index] : _data[index];
}

char MyString::operator[](size_t index) const
{
	return isSso() ? ssoData[index] : _data[index];
}
std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj.c_str();
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	size_t newStrSize = lhs.length() + rhs.length();

	if (newStrSize <= MyString::SSO_MAX_SIZE)
	{
		MyString res(lhs);
		res += rhs;
		return res;
	}
	else
	{
		MyString res(newStrSize + 1);
		strcpy(res._data, lhs.c_str());
		strcat(res._data, rhs.c_str());
		res.notUsingSso();
		return res;
	}
}
bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}