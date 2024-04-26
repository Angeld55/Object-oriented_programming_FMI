#pragma once
class GraduatedStudent
{
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;
	char quote[30 + 1] = "";

	void copyFrom(const GraduatedStudent& other);
	void moveFrom(GraduatedStudent&& other);
	void free();

public:
    GraduatedStudent(const char* name,
                     const int* grades,
                     size_t gradesCount,
                     const char* quote);

	GraduatedStudent(const GraduatedStudent& other);
	GraduatedStudent& operator=(const GraduatedStudent& other);
	~GraduatedStudent();

	GraduatedStudent(GraduatedStudent&& other);
	GraduatedStudent& operator=(GraduatedStudent&& other);


	void setName(const char* newName);
	void setGrades(const int* newGrades, size_t newGradesCount);
	void setQuote(const char* quote);

	const char* getName() const;
	const int* getGrades() const;
	unsigned getGradesCount() const;
	const char* getQuote() const;
};