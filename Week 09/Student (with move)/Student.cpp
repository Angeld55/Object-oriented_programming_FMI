#include "Student.h"
#include <cstring>
#include <utility>
#pragma warning (disable : 4996)


void Student::copyName(const char* newName)
{
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}
void Student::copyGrades(const int* newGrades, size_t newGradesCount)
{
	gradesCount = newGradesCount;
	
	grades = new int[gradesCount];
	for (unsigned i = 0; i < gradesCount; i++)
		grades[i] = newGrades[i];
}

void Student::copyFrom(const Student& other)
{
	copyName(other.name);
	copyGrades(other.grades, other.gradesCount);
}
void Student::moveFrom(Student&& other)
{
	name = other.name;
	other.name = nullptr;

	grades = other.grades;
	other.grades = nullptr;

	gradesCount = other.gradesCount;

	other.gradesCount = 0;
}


void Student::free()
{
	delete[] name;
	delete[] grades;
	name = nullptr;
	grades = nullptr;
	gradesCount = 0;
}

Student::Student(const char* name, const int* grades, size_t gradesCount)
{
	setName(name);
	setGrades(grades, gradesCount);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}


Student::Student(Student&& other) noexcept
{
	moveFrom(std::move(other));
}
Student& Student::operator=(Student&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

const char* Student::getName() const
{
	return name;
}

const int* Student::getGrades() const
{
	return grades;
}

const size_t Student::getGradesCount() const
{
	return gradesCount;
}

void Student::setName(const char* newName)
{
	if (!newName)
		return; //another check ?
	delete[] name;

	copyName(newName);
}

void Student::setGrades(const int* newGrades, size_t newGradesCount)
{
	if (!newGrades)
		return; //another check ?

	delete[] this->grades;
	copyGrades(newGrades, newGradesCount);
}
