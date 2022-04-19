#include "StringPool.h"

void StringPool::copyFrom(const StringPool& other)
{
	data = new MyString * [other.count];
	for (size_t i = 0; i < other.count; i++)
		data[i] = new MyString(*other.data[i]);
	count = other.count;
}

StringPool::StringPool()
{
	count = 0;
	data = nullptr;
}
void StringPool::free()
{
	for (size_t i = 0; i < count; i++)
		delete data[i]; //destr of MyString
	delete[] data;
}

void StringPool::resize(size_t newCount)
{
	MyString** resizedArray = new MyString*[newCount];

	for (size_t i = 0; i < std::min(newCount,count); i++)
		resizedArray[i] = data[i];
	count = newCount;

	delete[] data;
	data = resizedArray;
}

StringPool& StringPool::operator*=(const MyString& word)
{
	if ((*this)[word])
		return *this;
	resize(count + 1);
	data[count - 1] = new MyString(word);
	size_t currentStringPosition = count - 1;
	while (currentStringPosition > 0 && *data[currentStringPosition] < *data[currentStringPosition - 1])
	{
		std::swap(data[currentStringPosition], data[currentStringPosition - 1]);
		currentStringPosition--;
	}
	return *this;
}

StringPool& StringPool::operator/=(const MyString& str)
{
	int indexOfWord = findWord(str);
	if (indexOfWord == -1)
		return *this;

	delete data[indexOfWord];

	for (int i = indexOfWord; i < count - 1; i++)
		data[i] = data[i + 1];

	resize(count - 1);
	return *this;
}


int StringPool::findWord(const MyString& str) const
{
	int l = 0;
	int r = count - 1;

	while (l <= r)
	{
		size_t mid = l + (r - l) / 2;

		if (*data[mid] == str)
			return mid;
		else if (*data[mid] < str)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
bool StringPool::operator[](const MyString& str) const
{
	return findWord(str) != -1;
}

std::ostream& operator<<(std::ostream& stream, const StringPool& pool)
{
	for (size_t i = 0; i < pool.count; i++)
		stream << (*pool.data[i]) << " ";
	return stream;
}
void operator>>(const MyString& str, StringPool& pool)
{
	pool *= str;
}
StringPool& StringPool::operator+=(const StringPool& other)
{
	for (size_t i = 0; i < other.count; i++)
		(*this) *= (*other.data[i]);
	return *this;
}
StringPool& StringPool::operator-=(const StringPool& other)
{
	for (size_t i = 0; i < other.count; i++)
		(*this) /= (*other.data[i]);
	return *this;
}

StringPool operator+(const StringPool& lhs, const StringPool& rhs)
{
	StringPool copy(lhs);
	copy += rhs;
	return copy;
}
StringPool operator-(const StringPool& lhs, const StringPool& rhs)
{
	StringPool copy(lhs);
	copy -= rhs;
	return copy;
}

StringPool::StringPool(const StringPool& other)
{
	copyFrom(other);
}
StringPool& StringPool::operator=(const StringPool& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

StringPool::~StringPool() 
{
	free();
}