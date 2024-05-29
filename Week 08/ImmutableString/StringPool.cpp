#include "StringPool.h"
#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)


StringPool::StringPool()
{
	stringCapacity = 8;
	stringCount = 0;
	stringRecords = new StringRecord[stringCapacity];
}

const char* StringPool::getAllocatedString(const char* str)
{
	int index = findAllocatedString(str);

	if (index != -1) //the string is found
	{
		stringRecords[index].refCount++;

		//For debug pourpouses
		std::cout << "String found in cache, ref count: " << stringRecords[index].refCount << std::endl;
		//

		return stringRecords[index].str;
	}
	else //no such string in the collection -> we should allocate
	{
		//For debug pourpouses
		std::cout << "String NOT found in cache. Allocating.." << std::endl;
		//

		unsigned index = allocatedNewString(str);
		stringRecords[index].refCount++;
		return stringRecords[index].str;
	}
}

void StringPool::removeRecord(unsigned index)
{
	std::swap(stringRecords[index], stringRecords[stringCount - 1]);
	
	delete[] stringRecords[stringCount - 1].str;
	
	stringRecords[stringCount - 1].str = nullptr;
        stringRecords[stringCount - 1].refCount = 0;
	
        stringCount--;
}

void StringPool::releaseString(const char* str)
{
	int index = findAllocatedString(str); //this should not be -1

	stringRecords[index].refCount--;

	if (stringRecords[index].refCount == 0)
	{
		//For debug pourpouses
		std::cout << "Removing record: " << stringRecords[index].str  << " (No more refs)" << std::endl;
		//
		removeRecord(index);
	}
}

StringPool::~StringPool()
{
   for(int i = 0; i < stringCapacity; i++) //if the class is used correctly all strings will be deleted by this point.
	   delete[] stringRecords[i].str;
   delete[] stringRecords;
}

void StringPool::resize(unsigned newCap)
{
	StringRecord* newArr = new StringRecord[newCap];

	for (unsigned i = 0; i < stringCount; i++)
		newArr[i] = stringRecords[i]; //here a shallow copy is made (so we don't reallocate the strings)
        stringCapacity = newCap;
	delete[] stringRecords; //the array is deleted, but not the strings (the constructor of the StringRecord doesn't delete the string)
	stringRecords = newArr;
}

unsigned StringPool::allocatedNewString(const char* str)
{
	if (stringCount == stringCapacity)
		resize(stringCapacity * 2);

	unsigned firstFreeIndex = stringCount++;
	stringRecords[firstFreeIndex].str = new char[strlen(str) + 1];
	strcpy(stringRecords[firstFreeIndex].str, str);
	stringRecords[firstFreeIndex].refCount = 0;

	return firstFreeIndex;
}

int StringPool::findAllocatedString(const char* str) const
{
	for (int i = 0; i < stringCount; i++)
	{
		if (strcmp(str, stringRecords[i].str) == 0)
			return i;
	}
	return -1; //not such string!!
}
