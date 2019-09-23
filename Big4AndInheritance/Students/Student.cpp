#include "Student.h"
Student::Student(const char* name, int age, int fn): User(name,age)
{
	this->fn = fn;
}

void Student::ReceiveGrade(int grade)
{
	b.AddGrade(grade);
}