#include "SortedCollection.h"

int SortedCollection::lowerBound(int elem) const
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = -1;
	
	while (left <= right) 
	{
		int mid = left + (right - left) / 2;

		if (data[mid] < elem) 
		{
			left = mid + 1;
		}
		else
		{
			if (data[mid] == elem)
			{
				indexToReturn = mid;
			}

			right = mid - 1;
		}
	}

	return indexToReturn;
}

int SortedCollection::upperBound(int elem) const
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = -1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] > elem)
		{
			right = mid - 1;
		}
		else
		{
			if (data[mid] == elem)
			{
				indexToReturn = mid;
			}

			left = mid + 1;
		}
	}

	return indexToReturn;
}

void SortedCollection::add(int elem)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	int idx = size;

	while (idx != 0 && data[idx - 1] > elem) 
	{
		data[idx] = data[idx - 1];
		--idx;
	}

	data[idx] = elem;
	++size;
}

void SortedCollection::remove(int elem)
{
	int elementIndex = -1;

	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == elem)
		{
			elementIndex = i;
			break;
		}
	}

	if (elementIndex != -1) 
	{
		for (size_t i = elementIndex; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		--size;
	}
}

unsigned SortedCollection::count(int elem) const
{
	// Вземаме най - лявото и най - дясното срещане
	// на дадения елемент и намираме разликата в индексите.
	// Сложност: O(log(n))

	int leftIndex = lowerBound(elem);
	
	if (leftIndex == -1)
	{
		return 0;
	}

	int rightIndex = upperBound(elem);

	return rightIndex - leftIndex + 1;
}

bool SortedCollection::contains(int elem) const
{
	return lowerBound(elem) != -1;
}