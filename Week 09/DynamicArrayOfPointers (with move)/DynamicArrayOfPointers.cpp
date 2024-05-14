#include "DynamicArrayOfPointers.h"
#include <exception>

void DynamicArrayOfPointers::free()
{
	for (int i = 0; i < _capacity; i++)
		delete _data[i];
	delete[] _data;
}
void DynamicArrayOfPointers::copyFrom(const DynamicArrayOfPointers& other)
{
	_count = other._count;
	_capacity = other._capacity;

	_data = new A*[_capacity];
	for (int i = 0; i < _capacity; i++)
	{
		if (other._data[i] == nullptr)
			_data[i] = nullptr;
		else
			_data[i] = new A(*other._data[i]); //To reuse the A box
	}
}

void DynamicArrayOfPointers::resize(size_t newCap)
{
	A** newDataPtr = new A * [newCap] {nullptr};
	
	for (int i = 0; i < _capacity; i++)
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
void DynamicArrayOfPointers::moveFrom(DynamicArrayOfPointers&& other)
{
	_data = other._data;
	other._data = nullptr;

	_capacity = other._capacity;
	_count = other._count;
	
	other._count = 0; 
}

DynamicArrayOfPointers::DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept
{
	moveFrom(std::move(other));
}
DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(DynamicArrayOfPointers&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(const A& current)
{
	if (_count >= _capacity)
		resize(_capacity * 2);

	int ind = getFirstFreeIndex();
	if(ind == -1)
		return;
	
	_data[ind] = new A(current);
	_count++;
}

int DynamicArrayOfPointers::getFirstFreeIndex() const
{
	for (int i = 0; i < _capacity; i++)
		if (_data[i] == nullptr)
			return i;
	return -1; 
}


void DynamicArrayOfPointers::addAtFirstFreeIndex(A&& obj)
{
	if (_count >= _capacity)
		resize(_capacity * 2);
	
	int ind = getFirstFreeIndex();
	if(ind == -1)
		return;
	
	_data[ind] = new A(std::move(obj));  //move ctor
	_count++; 
}

bool DynamicArrayOfPointers::containsAt(unsigned ind) const
{
	return ind < _capacity && _data[ind] != nullptr;
}

void DynamicArrayOfPointers::removeAt(size_t index)
{
	if (index >= _capacity)
		return;

	delete _data[index];
	_data[index] = nullptr;
	_count--;

	/*if (_count == _capacity / 4 && _capacity / 2 > 8)
		resize(_capacity / 2);*/
}

const A& DynamicArrayOfPointers::operator[](size_t index) const
{
	return *_data[index]; //should be carefull for the empty places
}

A& DynamicArrayOfPointers::operator[](size_t index)
{
	return *_data[index]; //should be carefull for the empty places
}

void DynamicArrayOfPointers::popBack()
{
	if (size() == 0)
		return;

	delete _data[_count - 1];
	_count--;

	/*if (_count == _capacity / 4 && _capacity / 2 > 8)
		resize(_capacity / 2);*/
}

void DynamicArrayOfPointers::setAtIndex(const A& obj, size_t index)
{
	if (index >= _capacity) 
		resize(_capacity * 2);
	
	/*
	delete _data[index];
	_data[index] = new A(obj);
	*/

	if (_data[index] != nullptr)
		_data[index]->operator=(obj);
	else
	{
		_data[index] = new A(obj);
		_count++;
	}
}

void DynamicArrayOfPointers::setAtIndex(A&& obj, size_t index)
{

	if (_data[index] != nullptr)
		*_data[index] = obj;
	else
	{
		_data[index] = new A(std::move(obj)); //move c-tor
		_count++;
	}
}

size_t DynamicArrayOfPointers::size() const
{
	return _count;
}
