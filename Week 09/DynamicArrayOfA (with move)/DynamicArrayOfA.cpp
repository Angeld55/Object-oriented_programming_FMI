#include "DynamicArrayOfA.h"
#include <exception>
#include <utility>

DynamicArray::DynamicArray() : DynamicArray(8) {}

static size_t closestPowerOfAwo(size_t n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;

	return n + 1;
};

DynamicArray::DynamicArray(size_t capacity) : size(0)
{
	this->capacity = closestPowerOfAwo(capacity);
	arr = new A[this->capacity];
}


DynamicArray::DynamicArray(const DynamicArray& other)
{
	copyFrom(other);
}


DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{

	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


DynamicArray::~DynamicArray()
{
	free();
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept
{

	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void DynamicArray::copyFrom(const DynamicArray& other)
{

	arr = new A[other.capacity];

	for (size_t i = 0; i < other.size; i++)
		arr[i] = other.arr[i];

	size = other.size;
	capacity = other.capacity;
}

void DynamicArray::moveFrom(DynamicArray&& other)
{
	arr = other.arr;
	other.arr = nullptr;
	size = other.size;
	capacity = other.capacity;
}


void DynamicArray::free()
{
	delete[] arr;
}

void DynamicArray::resize(size_t newCap)
{

	A* temp = arr;
	arr = new A[newCap];

	for (size_t i = 0; i < size; i++)
		arr[i] = temp[i];

	capacity = newCap;
	delete[] temp;
}


void DynamicArray::pushBack(const A& newElem)
{
	if (size >= capacity)
		resize(capacity * 2);

	arr[size++] = newElem;
}

void DynamicArray::pushBack(A&& newElem)
{
	if (size >= capacity)
		resize(capacity * 2);

	arr[size++] = std::move(newElem); //move op =
}


void DynamicArray::popBack()
{
	if (size)
		size--;
	else
		throw std::length_error("Already empty!");

	if (size * 4 <= capacity && capacity > 1)
		resize(capacity / 2);
}

void DynamicArray::setAtIndex(const A& element, size_t index)
{
	if(index >= size)
		throw std::length_error("No such index!");

	arr[index] = element;
}

void DynamicArray::setAtIndex(A&& element, size_t index)
{
	if (index >= size)
		throw std::length_error("No such index!");

	arr[index] = std::move(element); //move op =
}


size_t DynamicArray::getSize() const
{
	return size;
}


bool DynamicArray::isEmpty() const
{
	return size == 0;
}



const A& DynamicArray::operator[](size_t index) const
{
	if (index > size)
		throw std::out_of_range("Out of range!");
	return arr[index];
}



A& DynamicArray::operator[](size_t index)
{
	if (index > size)
		throw std::out_of_range("Out of range!");
	return arr[index];
}
