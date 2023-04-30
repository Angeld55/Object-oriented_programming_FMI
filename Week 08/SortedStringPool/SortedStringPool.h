#pragma once
#include <iostream>
#include <cstring>

class SortedStringPool
{

	struct LittleString
	{
	private:
		char _str[64] = "";
		unsigned refCount = 0;
		void setStr(const char* str)
		{
			//if (strlen(str) > 63) //the check is done in addString in SortedStringPool
				//return;
			strcpy(_str, str);
		}

	public:

		explicit LittleString(const char* str)
		{
			setStr(str);
		}

		const char* getStr() const
		{
			return _str;
		}

		unsigned getRefsCount() const
		{
			return refCount;
		}

		void incrementRefCount()
		{
			refCount++;
		}
		void decrementRefCount()
		{
			refCount--;
		}

	};

	LittleString** data;
	size_t capacity;
	size_t size;

	void copyFrom(const SortedStringPool& other);
	void free();
	void resize(size_t newCap);

public:

	SortedStringPool();
	SortedStringPool(const SortedStringPool& other);
	SortedStringPool& operator=(const SortedStringPool& other);
	~SortedStringPool();

	bool addString(const char* str);
	void removeAtIndex(unsigned ind);
	long long contains(const char* str) const; //returns the LAST index of the string or -1 if the string is not present
	void printAll() const;

};