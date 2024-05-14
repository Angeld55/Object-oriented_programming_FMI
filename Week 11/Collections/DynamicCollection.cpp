#include "DynamicCollection.h"
#include <iostream>

void DynamicCollection::free()
{
	delete[] data;
}

void DynamicCollection::copyFrom(const DynamicCollection& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new int[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void DynamicCollection::moveFrom(DynamicCollection&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;

	other.size = other.capacity = 0;
}

DynamicCollection::DynamicCollection(DynamicCollection&& other)
{
	moveFrom(std::move(other));
}

DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void DynamicCollection::resize(size_t nCap)
{
	int* newData = new int[nCap];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = nCap;
}

DynamicCollection::DynamicCollection(size_t cap)
{
	size = 0;
	capacity = cap;

	data = new int[capacity];
}

DynamicCollection::DynamicCollection()
{
	size = 0;
	capacity = 8;

	data = new int[capacity];
}

DynamicCollection::DynamicCollection(const DynamicCollection& other)
{
	copyFrom(other);
}

DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicCollection::~DynamicCollection()
{
	free();
}