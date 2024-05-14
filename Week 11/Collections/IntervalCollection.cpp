#include "IntervalCollection.h"
#include <iostream>

IntervalCollection::IntervalCollection(int start, int end)
{
	if (end < start)
	{
		std::swap(start, end);
	}

	this->start = start;
	this->end = end;
	int size = end - start;

	data = new int[size] {0};
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