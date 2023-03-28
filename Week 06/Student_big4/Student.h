#pragma once


class Student
{
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;

	void copyName(const char* newName);
	void copyGrades(const int* newGrades, size_t newGradesCount);

	void copyFrom(const Student& other);
	void free();

public:
	Student(const char* name, const int* grades, size_t gradesCount);

	//BIG 4
	Student() = default; //grades, name will be nullptr.
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	const char* getName() const;
	const int* getGrades() const;

	const size_t getGradesCount() const;

	void setName(const char* newName);
	void setGrades(const int* newGrades, size_t newGradesCount);
};

