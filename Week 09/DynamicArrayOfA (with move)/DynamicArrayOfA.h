#pragma once
#include <iostream>

struct A
{
	int a = 4;
	int b = 3;
};
class DynamicArray
{

private:
	A* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	void moveFrom(DynamicArray&& other);
public:
	DynamicArray();
	DynamicArray(size_t capacity);
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	DynamicArray(DynamicArray&& other) noexcept;
	DynamicArray& operator=(DynamicArray&& other) noexcept;

private:
	void copyFrom(const DynamicArray& other);
	void free();
	void resize(size_t newCap);

public:
	void pushBack(const A& newElem); //add a new element in the end
	void pushBack(A&& newElem); //add a new element in the end

	void popBack(); //removes the last element

	void setAtIndex(const A& element, size_t index);
	void setAtIndex(A&& element, size_t index);

	size_t getSize() const;
	bool isEmpty() const;

	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};
