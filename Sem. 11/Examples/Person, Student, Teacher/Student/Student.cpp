	#include "Student.h"

Student::Student(const char* name, int age, size_t fn) : Person(name, age)
{
	setFn(fn);
}

size_t Student::getFn() const
{
	return fn;
}

void Student::setFn(size_t fn)
{
	
	if (fn < 100)
		fn = 100;
	this->fn = fn;
}

// The compiler will make:

//Student(const Student& other) : Person(other), fn(other.fn), grade(other.grade)  OK!!!
//{}

//Student& operator=(const Student& other)                     OK!!!!
//{
//	if (this != &other)
//	{
//		Person::operator=(other); //handles the deletion and copying of the base class
//		fn = other.fn;
//	}
//	return *this;
//}