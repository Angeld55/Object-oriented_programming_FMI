#include "Student.h"

Student::Student(const char* name, size_t fn)
{
	setName(name);
	setFn(fn);
}

void Student::setFn(size_t fn)
{
	if (fn < 80000 || fn > 83000)
		throw std::exception("Invalid fn");

	this->fn = fn;
}
void Student::setName(const char* name)
{
	if (strlen(name) > MAX_NAME_LENGTH)
		throw std::exception("Name is too long!");

	strcpy(this->name, name);
}

size_t Student::getFN() const
{
	return fn;
}
const char* Student::getName() const
{
	return name;
}

void Student::addGrade(const char* taskName, size_t grade)
{
	if (gradesCount == MAX_GRADES_COUNT)
		throw std::exception("Error! Too many grades!");

	Grade currentGrade(taskName, grade);
	grades[gradesCount++] = currentGrade;
}

void Student::print() const
{
	std::cout << name << " " << fn << std::endl;
}