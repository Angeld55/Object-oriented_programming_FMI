#pragma once
#include <cstdint>
#include <fstream>

class MyVector {
private:
	int32_t* data;
	int size;

	void free();
	void copyFrom(const MyVector& other);
public:
	MyVector(int size);
	MyVector(int32_t* data, int size);
	~MyVector();

	MyVector& operator=(const MyVector& other);
	MyVector(const MyVector& other);
	int operator[](int index) const;

	void readFromFile(std::istream& file, unsigned count);

	int getSize() const;
};