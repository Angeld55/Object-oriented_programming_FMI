#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student
{
	char name[30];
	int age;
	int fn;
};

void initStudent(Student& st, const char* name, int age, int fn)
{
	strcpy(st.name, name);
	st.age = age;
	st.fn = fn;
}

void saveToFile(const Student* students, size_t count, ofstream& file)
{
	file.write((const char*)students, count * sizeof(Student));
}


int main()
{
  constexpr size_t size = 4;
	Student* arr = new Student[size];
	initStudent(arr[0], "ivan", 44, 1234);
	initStudent(arr[1], "petur", 12, 765);
	initStudent(arr[2], "alex", 15, 44);
	initStudent(arr[3], "katerina", 19, 12134);

	ofstream file("students.dat", ios::binary);
		
	if(!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		delete[] arr; //!
		return -1;
	}
		
	saveToFile(arr, size, file);
	
	delete[] arr;
	
	return 0;
}
