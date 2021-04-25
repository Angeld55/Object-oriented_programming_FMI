#pragma once

#include <iostream>

class Grade
{
	size_t gradeValue;
	char* taskName;

	void free();
	void copyFrom(const Grade& other);
public:
	Grade();

	Grade(const char* taskName, size_t gradeValue);

	Grade(const Grade& other);
	Grade& operator=(const Grade& other);
	~Grade();

	const char* getTaskName() const;
	size_t getGrade() const;

	void setTaskName(const char* name);
	void setGrade(size_t grade);
};