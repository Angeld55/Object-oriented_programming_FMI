#pragma once
#include "User.h"
#include "GradesBook.h"

class Student : public User
{
public:
	int fn;
	GradesBook b;

	Student(const char* name, int age, int fn);
	void ReceiveGrade(int grade);
	

};
