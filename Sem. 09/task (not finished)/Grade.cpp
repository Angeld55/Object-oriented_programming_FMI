#include "Grade.h"


Grade::Grade() : taskName(nullptr)
{
	setTaskName("Unknown");
	setGrade(2);
}

Grade::Grade(const char* taskName, size_t gradeValue) : taskName(nullptr)
{
	setTaskName(taskName);
	setGrade(gradeValue);
}

void Grade::free()
{
	delete[] taskName;
}
void Grade::copyFrom(const Grade& other)
{
	gradeValue = other.gradeValue;

	taskName = new char[strlen(other.taskName) + 1];
	strcpy(taskName, other.taskName);
}

Grade::Grade(const Grade& other)
{
	copyFrom(other);
}

Grade& Grade::operator=(const Grade& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Grade::~Grade()
{
	free();
}

const char* Grade::getTaskName() const
{
	return taskName;
}
size_t Grade::getGrade() const
{
	return gradeValue;
}

void Grade::setGrade(size_t grade)
{
	if (grade < 2 || grade > 6)
		throw std::exception("error!");
	
	gradeValue = grade;
}

void Grade::setTaskName(const char* name)
{
	delete[] taskName;
	taskName = new char[strlen(name) + 1];
	strcpy(taskName, name);
}