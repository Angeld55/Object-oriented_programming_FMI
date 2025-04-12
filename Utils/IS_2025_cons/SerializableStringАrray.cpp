#include "SerializableString¿rray.h"
#include <cstring>
#include <stdexcept>
#include <fstream>
#include <iostream>

#pragma warning (disable : 4996)
SerializableString¿rray::SerializableString¿rray(size_t maxStringCount, size_t maxStringLength) : metaData{ maxStringCount, maxStringLength }
{
	data = new char[metaData.getAllocationSize()];
}

SerializableString¿rray::SerializableString¿rray(const SerializableString¿rray& other) : metaData(other.metaData)
{
	copyDynamic(other);
}

SerializableString¿rray::SerializableString¿rray(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::binary);
	if(!ifs)
		throw std::runtime_error("File did not open while reading!");

	ifs.read(reinterpret_cast<char*>(&metaData), sizeof(metaData));
	size_t newLen = metaData.getAllocationSize();
	std::cout << newLen << std::endl;
	data = new char[newLen];
	ifs.read(data, newLen);
}


SerializableString¿rray& SerializableString¿rray::operator=(const SerializableString¿rray& other)
{
	if (this != &other)
	{
		metaData = other.metaData;
		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}
SerializableString¿rray::~SerializableString¿rray()
{
	freeDynamic();
}

void SerializableString¿rray::freeDynamic()
{
	delete[] data;
	data = nullptr; 
}

void SerializableString¿rray::copyDynamic(const SerializableString¿rray& other)
{
	size_t newLen = other.metaData.getAllocationSize();
	data = new char[newLen];
	for (int i = 0; i < newLen; i++)
		data[i] = other.data[i];
}

size_t SerializableString¿rray::getSize() const
{
	return metaData.size;
}

size_t SerializableString¿rray::getCapacity() const
{
	return metaData.maxStringCount;
}

bool SerializableString¿rray::isFull() const
{
	return getCapacity() == getSize();
}

void SerializableString¿rray::addString(const char* str)
{
	if (!str)
		throw std::invalid_argument("nullptr given");
	if(strlen(str) > metaData.maxStringLength)
		throw std::invalid_argument("String to long!");
	if (isFull())
		throw std::logic_error("Full collection");

	size_t beginIndexOfNewString = metaData.size * (metaData.maxStringLength + 1);
	strcpy(data + beginIndexOfNewString, str);
	metaData.size++;
}

const char* SerializableString¿rray::get(size_t index) const
{
	if (index >= metaData.size)
		throw std::out_of_range("No such index!");

	size_t beginIndexOfCurrString = index * (metaData.maxStringLength + 1);
	return data + beginIndexOfCurrString;
}

void SerializableString¿rray::writeToBinary(const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs)
		throw std::runtime_error("File did not open");

	ofs.write(reinterpret_cast<const char*>(&metaData), sizeof(MetaData));
	ofs.write(data, metaData.getAllocationSize());
}

size_t SerializableString¿rray::MetaData::getAllocationSize() const
{
	return maxStringCount * (maxStringLength + 1);
}