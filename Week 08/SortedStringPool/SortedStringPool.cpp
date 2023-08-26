#include "SortedStringPool.h"

void SortedStringPool::copyFrom(const SortedStringPool& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new LittleString * [capacity] {nullptr};

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
		data[i]->incrementRefCount();
	}
}
void SortedStringPool::free()
{
	for (int i = 0; i < size; i++)
	{
		if (data[i]->getRefsCount() == 1)
			delete data[i];
		else
			data[i]->decrementRefCount();
	}
	delete[] data;
}

SortedStringPool::SortedStringPool()
{
	capacity = 8;
	size = 0;
	data = new LittleString * [capacity] {nullptr};
}

void SortedStringPool::resize(size_t newCap)
{
	LittleString** newData = new LittleString * [newCap] {nullptr};
	capacity = newCap;

	for (unsigned i = 0; i < size; i++)
		newData[i] = data[i];

	delete[] data;
	data = newData;
}

bool SortedStringPool::addString(const char* str)
{

	if (strlen(str) >= 64)
		return false;

	if (size == capacity)
		resize(capacity * 2);

	int currentIndex = size - 1;
	int lastStrcmpRes = -1;
	while (currentIndex >= 0 && ((lastStrcmpRes = strcmp(str, data[currentIndex]->getStr())) < 0))
	{
		data[currentIndex + 1] = data[currentIndex];
		currentIndex--;
	}
	//currentIndex + 1 å ïîçèöèÿòà

	if (currentIndex + 1 > 0 && lastStrcmpRes == 0)
	{
		data[currentIndex + 1] = data[currentIndex];
	}
	else
	{
		data[currentIndex + 1] = new LittleString(str);
	}
	data[currentIndex + 1]->incrementRefCount();

	size++;
	return true;
}

void SortedStringPool::removeAtIndex(unsigned ind)
{
	if (ind > size)
		return;

	if (data[ind]->getRefsCount() == 1)
		delete data[ind];
	else
		data[ind]->decrementRefCount();

	for (int i = ind; i < size - 1; i++)
		data[i] = data[i + 1];

	size--;
}

long long SortedStringPool::contains(const char* str) const
{
	long long start = 0;
	long long end = size - 1;

	long long result = -1;
	while (start <= end)
	{
		long long mid = start + (end - start) / 2;

		int strCmpRes = strcmp(str, data[mid]->getStr());

		if (strCmpRes == 0)
		{
			result = mid;
			start = mid + 1;
		}
		else if (strCmpRes < 0)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return result;
}


void SortedStringPool::printAll() const
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << data[i]->getStr() << " ";
	}
	std::cout << std::endl;
}

SortedStringPool::SortedStringPool(const SortedStringPool& other)
{
	copyFrom(other);
}
SortedStringPool& SortedStringPool::operator=(const SortedStringPool& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
SortedStringPool::~SortedStringPool()
{
	free();
}
