#include "UniCourse.h"

UniCourse::UniCourse(const char* lecturerName) : UniCourse(lecturerName, "", "", "")
{}
UniCourse::UniCourse(const char* lecturerName, const char* assistant1Name) : UniCourse(lecturerName, assistant1Name, "", "")
{}
UniCourse::UniCourse(const char* lecturerName, const char* assistant1Name, const char* assistant2Name) : UniCourse(lecturerName, assistant1Name, assistant2Name, "")
{}

UniCourse::UniCourse(const char* lecturerName, const char* assistant1Name, const char* assistant2Name, const char* assistant3Name)
{
	this->lecturerName = new char[strlen(lecturerName) + 1];
	strcpy(this->lecturerName, lecturerName);

	assistantsNames[0] = new char[strlen(assistant1Name) + 1];
	strcpy(assistantsNames[0], assistant1Name);

	assistantsNames[1] = new char[strlen(assistant2Name) + 1];
	strcpy(assistantsNames[1], assistant2Name);

	assistantsNames[2] = new char[strlen(assistant3Name) + 1];
	strcpy(assistantsNames[2], assistant3Name);

	capacity = 8;
	size = 0;

	students = new Student*[capacity];
}


void UniCourse::copyFrom(const UniCourse& other)
{
	lecturerName = new char[strlen(other.lecturerName) + 1];
	strcpy(lecturerName, other.lecturerName);

	for (int i = 0; i < 3; i++)
	{
		if (other.assistantsNames[i] != nullptr)
		{
			assistantsNames[i] = new char[strlen(other.assistantsNames[i]) + 1];
			strcpy(assistantsNames[i], other.assistantsNames[i]);
		}
	}


	students = new Student*[other.capacity];

	for (int i = 0; i < other.size; i++)
		students[i] = new Student(*other.students[i]);

	capacity = other.capacity;
	size = other.size;

}
void UniCourse::free()
{
	delete[] lecturerName;

	for (int i = 0; i < 3; i++)
		delete[] assistantsNames[i];

	for (int i = 0; i < size; i++)
		delete students[i];

	delete[] students;
}

UniCourse::UniCourse(const UniCourse& other)
{
	copyFrom(other);
}

UniCourse& UniCourse::operator=(const UniCourse& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
UniCourse::~UniCourse()
{
	free();
}
void UniCourse::addStudent(const char* name, size_t fn)
{
	if (size == capacity)
		resize();

	Student* current = new Student(name, fn);
	students[size++] = current;
}

void UniCourse::resize()
{
	Student** temp = new Student*[capacity *= 2];

	for (int i = 0; i < size; i++)
		temp[i] = students[i];

	delete[] students;

	students = temp;
}

size_t UniCourse::findStudentByFn(size_t fn)
{
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getFN() == fn)
			return i;
	}
	return -1;
}
void UniCourse::removeStudent(size_t fn)
{
	size_t indexOfStudent = findStudentByFn(fn);
	if (fn == -1)
		return;
	
	delete students[indexOfStudent];

	for (int i = indexOfStudent; i < size - 1; i++)
		students[i] = students[i + 1];

	size--;

}

void UniCourse::print()
{
	for (int i = 0; i < size; i++)
		students[i]->print();
}