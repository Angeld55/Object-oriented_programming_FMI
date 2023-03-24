#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//constructor and destructor example. No copying!
struct Student
{
	char* name;
	int age;

	Student(const char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}
	
	void print() const
	{
		std::cout << "Name: " << name << ", age: " << age << std::endl;
	}
	~Student()
	{
		delete[] name;
	}
};
int main()
{
	Student s("Ivan", 33);

	Student* ptr = new Student("Petur", 17);

	s.print();
	ptr->print();

	delete ptr; //calls destructor of ptr
}//calls destructor of s
