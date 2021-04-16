#include "Student.h"

class UniCourse
{
	char* lecturerName;
	char* assistantsNames[3];

	Student** students;
	size_t capacity;
	size_t size;

	void copyFrom(const UniCourse& other);
	void free();

	size_t findStudentByFn(size_t fn);

	void resize();

public:
	UniCourse(const char* lecturerName);
	UniCourse(const char* lecturerName, const char* assistant1Name);
	UniCourse(const char* lecturerName, const char* assistant1Name, const char* assistant2Name);
	UniCourse(const char* lecturerName, const char* assistant1Name, const char* assistant2Name, const char* assistant3Name);


	UniCourse(const UniCourse& other);
	UniCourse& operator=(const UniCourse& other);
	~UniCourse();

	void addStudent(const char* name, size_t fn);
	void removeStudent(size_t fn);

	void print();

};