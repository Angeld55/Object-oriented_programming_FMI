#include <iostream>
#include "../Person/Person.h"

class Student : public Person
{
	size_t fn = 0;
public:
	Student() = default;
	Student(const char* name, int age, size_t fn);
	
	size_t getFn() const;
	void setFn(size_t fn);


	// No need for big 4, since there is NO dyn. memory in Student
	// The compiler will generate valid:

	//Student(const Student& other);
	//Student& operator=(const Student& other); //no need 
	// ~Student()
	
	//See on the .cpp file how the compiler creates them

};
