#include <iostream>
#include "Person/Person.h"
#include "Student/Student.h"
#include "Teacher/Teacher.h"

int main()
{

	char subjects[3][20] = { "English", "Mathematics", "Physics" };
	
	char** subjectsPointers = new char* [3];
	subjectsPointers[0] = subjects[0];
	subjectsPointers[1] = subjects[1];
	subjectsPointers[2] = subjects[2];

	Teacher t("Prof. Ivanov", 33, subjectsPointers, 3);

	std::cout << t.getName() << std::endl;

	delete[] subjectsPointers; //only the pointers - not the data!

}
