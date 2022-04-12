#include "Vector.h"

void Vector::resize()
{
	capacity *= 2;
	int* newArr = new int[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	free();
	arr = newArr;
}

void Vector::free()
{
	delete[] arr;
}

void Vector::copyFrom(const Vector& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Vector::Vector()
{
	arr = new int[2];
	capacity = 2;
	size = 0;
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::~Vector()
{
	free();
}

void Vector::push_back(const int element)
{
	if (size < capacity) {
		arr[size] = element;
		size++;
	}
	else
	{
		resize();
		push_back(element);
	}
}

int Vector::getSize() const
{
	return size;
}

int& Vector::operator[](const int index)
{
	if (index >= 0 && index < size) {
		return arr[index];
	}
	throw std::exception("Out of range exception");

}

const int& Vector::operator[](int index) const
{
	if (index >= 0 && index < size) {
		return arr[index];
	}
	throw std::exception("Out of range exception");
}
