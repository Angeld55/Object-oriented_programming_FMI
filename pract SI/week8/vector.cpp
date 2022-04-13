#include "vector.h"
#include<exception>

void vector::free() {
	delete[] data;
}

void vector::copyFrom(const vector& other) {
	size = other.size;
	capacity = other.capacity;

	data = new int[capacity];

	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

void vector::resize() {
	capacity = 2 * capacity;

	int* newMemory = new int[capacity];

	for (int i = 0; i < size; i++)
		newMemory[i] = data[i];

	delete[] data;
	data = newMemory;
}

vector::vector() {
	size = 0;
	capacity = 8;
	data = new int[capacity];
}

vector::vector(const vector& other) {
	copyFrom(other);
}

vector& vector::operator=(const vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

size_t vector::getSize() const {
	return size;
}

void vector::push_back(int elem) {
	if (size == capacity)
		resize();

	data[size++] = elem;
}



int& vector::operator[](size_t index) {
	if (index >= size)
		throw std::exception("out of range");
	return data[index];
}

const int vector::operator[](size_t index) const {
	if (index >= size)
		throw std::exception("out of range");
	return data[index];
}

vector::~vector() {
	free();
}
