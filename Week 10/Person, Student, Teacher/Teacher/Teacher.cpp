#include "Teacher.h"

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount) : Person(name, age)
{
	this->subjects = new char* [subjectsCount];

	for (size_t i = 0; i < subjectsCount; i++)
	{
		this->subjects[i] = new char[strlen(subjects[i]) + 1];
		strcpy(this->subjects[i], subjects[i]);
	}
	this->subjectsCount = subjectsCount;
}

void Teacher::free()
{
	for (size_t i = 0; i < subjectsCount; i++)
		delete[] subjects[i];
	delete[] subjects;
}
void Teacher::copyFrom(const Teacher& other)
{
	subjects = new char* [other.subjectsCount];
	
	for (size_t i = 0; i < other.subjectsCount; i++)
	{
		subjects[i] = new char[strlen(other.subjects[i]) + 1];
		strcpy(subjects[i], other.subjects[i]);
	}

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


Teacher::Teacher(Teacher&& other) : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other)
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
