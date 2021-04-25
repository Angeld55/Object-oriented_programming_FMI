#include "Grade.h"

const size_t MAX_NAME_LENGTH = 30;
const size_t MAX_GRADES_COUNT = 20;
class Student
{
public:
		
	Student(const char* name, size_t fn);

	void setFn(size_t fn);
	void setName(const char* name);

	size_t getFN() const;
	const char* getName() const;

	void addGrade(const char* taskName, size_t grade);
	

	void print() const;
private:
	char name[MAX_NAME_LENGTH + 1];
	size_t fn;
	
	Grade grades[MAX_GRADES_COUNT];
	size_t gradesCount;


};