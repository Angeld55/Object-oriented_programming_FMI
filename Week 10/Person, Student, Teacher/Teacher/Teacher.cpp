#include "Teacher.h"
#pragma warning (disable:4996)


static char** copyArrayOfString(const char* const* strings, size_t size)
{
	char** res = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		res[i] = new char[strlen(strings[i]) + 1];
		strcpy(res[i], strings[i]);
	}

	return res;
}

static void freeArraysOfString(char** strings, unsigned stringsCount)
{
	for (size_t i = 0; i < stringsCount; i++)
		delete[] strings[i];
	delete[] strings;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount) : Person(name, age)
{
	this->subjects = copyArrayOfString(subjects, subjectsCount);
	this->subjectsCount = subjectsCount;
}

void Teacher::free()
{
	freeArraysOfString(subjects, subjectsCount);
}
void Teacher::copyFrom(const Teacher& other)
{
	subjects = copyArrayOfString(other.subjects, other.subjectsCount);
	subjectsCount = other.subjectsCount;
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	copyFrom(other); //only the teacher stuff is copied
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other); //delete data of person + copy the data from person
		free(); //Teacher::free();
		copyFrom(other); //Teacher::copyFrom()
	}
	return *this;
}
void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;
	other.subjects = nullptr;
	other.subjectsCount = 0;
}


Teacher::Teacher(Teacher&& other) noexcept : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this != &other)
	{
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
} // destr person
