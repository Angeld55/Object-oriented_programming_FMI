#include "NormalCollection.h"
#include <iostream>

void NormalCollection::add(int elem)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	data[size++] = elem;
}

void NormalCollection::remove(int elem)
{
	int elemIndex = -1;

	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == elem)
		{
			elemIndex = i;
			break;
		}
	}

	if (elemIndex != -1)
	{
		std::swap(data[elemIndex], data[size - 1]);
		size--;
	}
}

unsigned NormalCollection::count(int elem) const
{
	unsigned elementCounter = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == elem)
		{
			++elementCounter;
		}
	}

	return elementCounter;
}

bool NormalCollection::contains(int elem) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == elem)
		{
			return true;
		}
	}
	return false;
}