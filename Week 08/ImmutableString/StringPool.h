#pragma once

class StringPool
{
public:
	StringPool();
	const char* getAllocatedString(const char* str);
	void releaseString(const char* str); 
        StringPool(const StringPool&) = delete;
        StringPool& operator=(const StringPool&) = delete;
        ~StringPool();
private:

	unsigned allocatedNewString(const char* str);
	void resize(unsigned newCap);
	int findAllocatedString(const char* str) const;

	void removeRecord(unsigned index);

	struct StringRecord
	{
		char* str = nullptr;
		unsigned refCount = 0;
	};

	StringRecord* stringRecords;
	size_t stringCount = 0;
	size_t stringCapacity = 0;
};
