#include "MyString.h"

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result; //не заделя памет!

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[length() + other.length() + 1];
	result[0] = '\0'; //заради strcat!!
	strcat(result, _data);
	strcat(result, other._data);

	delete[] _data;
	_data = result;
	size = length() + other.length();

	return *this;
}

MyString::MyString()
{
	_data = new char[1];
	_data[0] = '\0';
	size = 0;
}
MyString::MyString(const char* data)
{
	size = strlen(data);
	_data = new char[size + 1];
	strcpy(_data, data);
	
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


void MyString::free()
{
	delete[] _data;
	_data = nullptr;
}
MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return size;
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	_data = new char[size + 1];
	strcpy(_data, other._data);
}

char& MyString::operator[](size_t index) //Неконстантен достъп
{
	return _data[index];
}

char MyString::operator[](size_t index) const //Константен достъп 
{
	return _data[index];
}
