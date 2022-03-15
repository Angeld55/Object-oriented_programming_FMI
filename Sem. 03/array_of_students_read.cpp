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


size_t getFileSize(ifstream& f)
{
	size_t currentPos = f.tellg();
	f.seekg(0, ios::end);
	size_t size = f.tellg();
	
	f.seekg(currentPos);
	return size;
}

void readFromFile(Student*& ptr, size_t& studentsCount, ifstream& f)
{
	size_t sizeOfFile = getFileSize(f);
	studentsCount = sizeOfFile / sizeof(Student);
	ptr = new Student[studentsCount];
	f.read((char*)ptr, sizeOfFile);
}


int main()
{
	Student* arr;
	size_t count;
	ifstream file("students.dat");
	readFromFile(arr, count, file);

	for (int i = 0; i < count; i++)
		std::cout << "Name: " << arr[i].name << ", age: " << arr[i].age << ", fn: " << arr[i].fn << std::endl;
	
	delete[] arr;
}