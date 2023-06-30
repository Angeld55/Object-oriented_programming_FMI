#include "DynamicArrayOfPointers.h"
#include <exception>

void DynamicArrayOfPointers::free()
{
	for (int i = 0; i < _count; i++)
		delete _data[i];
	delete[] _data;
}
void DynamicArrayOfPointers::copyFrom(const DynamicArrayOfPointers& other)
{
	_count = other._count;
	_capacity = other._capacity;

	_data = new A*[_capacity];
	for (int i = 0; i < _count; i++)
	{
		if (other._data[i] == nullptr)
			_data[i] = nullptr;
		else
			_data[i] = new A(*other._data[i]);
	}
}

void DynamicArrayOfPointers::resize(size_t newCap)
{
	A** newDataPtr = new A * [newCap] {nullptr};
	
	for (int i = 0; i < _count; i++)
		newDataPtr[i] = _data[i];

	delete[] _data;
	_data = newDataPtr;

	_capacity = newCap;
}


DynamicArrayOfPointers::DynamicArrayOfPointers()
{
	_capacity = 8;
	_data = new A*[_capacity] {nullptr};
}

DynamicArrayOfPointers::DynamicArrayOfPointers(const DynamicArrayOfPointers& other)
{
	copyFrom(other);
}


DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(const DynamicArrayOfPointers& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicArrayOfPointers::~DynamicArrayOfPointers()
{
	free();
}

void DynamicArrayOfPointers::pushBack(const A& current)
{
	if (_count >= _capacity)
		resize(_capacity * 2);

	_data[_count++] = new A(current);
}

void DynamicArrayOfPointers::removeAt(size_t index)
{
	if (index >= _count)
		return;

	delete _data[index];
	
	for (size_t i = index; i < count - 1; i++){ //
		_data[index] = _data[index + 1];    // _data[index] = _data[count - 1];
	}					    //
	
	_data[count - 1] = nullptr;
	_count--;
}

const A& DynamicArrayOfPointers::operator[](size_t index) const
{
	return *_data[index];
}

A& DynamicArrayOfPointers::operator[](size_t index)
{
	return *_data[index];
}

void DynamicArrayOfPointers::popBack()
{
	if (size() == 0)
		return;

	delete _data[_count - 1];
	_count--;
}

void DynamicArrayOfPointers::setAt(const A& obj, size_t index)
{
	/*
	delete _data[index];
	_data[index] = new A(obj);
	*/

	if (_data[index] != nullptr)
		*_data[index] = obj;
	else
	{
		_data[index] = new A(obj);
		_count++;
	}
}


size_t DynamicArrayOfPointers::size() const
{
	return _count;
}
