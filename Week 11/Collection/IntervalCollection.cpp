#include "IntervalCollection.h"
#include<exception>
void IntervalCollection::free()
{
	delete[] data;
}
void IntervalCollection::copyFrom(const IntervalCollection& other)
{
	start = other.start;
	end = other.end;
	unsigned length = intervalLength();

	data = new int[length];

	for (size_t i = 0; i < length; i++)
	{
		data[i] = other.data[i];
	}
}
IntervalCollection::IntervalCollection(size_t start, size_t end)
{
	if (end < start)
	{
		throw std::exception();
	}

	this->start = start;
	this->end = end;
	size_t size = end - start;

	data = new int[size] {0};
}

IntervalCollection::IntervalCollection(const IntervalCollection& other)
{
	copyFrom(other);
}

IntervalCollection::IntervalCollection(IntervalCollection&& other)
{
	moveFrom(std::move(other));
}

IntervalCollection& IntervalCollection::operator=(const IntervalCollection& other)
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}

IntervalCollection& IntervalCollection::operator=(IntervalCollection&& other)
{
	if (this != &other) 
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

unsigned IntervalCollection::intervalLength() const
{
	return end - start;
}

void IntervalCollection::add(int elem)
{
	if (elem < start || elem > end)
	{
		return;
	}

	int index = elem - start;

	++data[index];
}

void IntervalCollection::remove(int elem)
{
	if (elem < start || elem > end)
	{
		return;
	}

	int index = elem - start;
	
	if (data[index] == 0)
	{
		return;
	}

	--data[index];
}

unsigned IntervalCollection::count(int elem) const
{
	if (elem < start || elem > end)
	{
		return 0;
	}

	int index = elem - start;

	return data[index];
}

bool IntervalCollection::contains(int elem) const
{
	return count(elem) > 0;
}

void IntervalCollection::moveFrom(IntervalCollection&& other) 
{
	this->data = other.data;
	other.data = nullptr;

	other.start = other.end = 0;
} 

IntervalCollection::~IntervalCollection()
{
	free();
}
