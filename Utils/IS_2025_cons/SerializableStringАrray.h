#pragma once

class SerializableString¿rray
{
public:
	SerializableString¿rray(size_t maxStringCount,
		size_t maxStringLength);

	SerializableString¿rray(const char* fileName);


	SerializableString¿rray(const SerializableString¿rray& other);
	SerializableString¿rray& operator=(const SerializableString¿rray& other);
	~SerializableString¿rray();


	void addString(const char* str);
	const char* get(size_t index) const;

	size_t getSize() const;
	size_t getCapacity() const;
	bool isFull() const;

	void writeToBinary(const char* fileName);
private:

	void freeDynamic();
	void copyDynamic(const SerializableString¿rray& other);

	char* data = nullptr;

	struct MetaData {
		size_t maxStringCount = 0;
		size_t maxStringLength = 0;
		size_t size = 0;
		size_t getAllocationSize() const;
	} metaData;

};

