#include "MyVector.h"
#include <iostream>

void MyVector::free()
{
	delete[] data;
}
void MyVector::copyFrom(const MyVector& other)
{
	data = new int[other.size];
	for (int i = 0; i < other.size; i++)
		data[i] = other.data[i];
	size = other.size;
}
MyVector::MyVector(int size) : size(size)
{
	data = new int32_t[size];
}

MyVector::MyVector(int32_t* data, int size)
{
	if (!data) {
		throw std::exception("data cannot be nullptr");
	}
	this->data = new int32_t[size];
	for (int i = 0; i < size; i++) {
		this->data[i] = data[i];
	}
	this->size = size;
}

MyVector::~MyVector()
{
	free();
}

MyVector& MyVector::operator=(const MyVector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyVector::MyVector(const MyVector& other)
{
	copyFrom(other);
}

int MyVector::operator[](int index) const
{
	return data[index];
}

void MyVector::readFromFile(std::istream& file, unsigned count)
{
	file.read((char*)data, count * sizeof(int32_t));
}

int MyVector::getSize() const
{
	return size;
}