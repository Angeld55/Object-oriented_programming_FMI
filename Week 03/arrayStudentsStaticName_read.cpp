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
			
	if(!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}
		
	readFromFile(arr, count, file);

	for (int i = 0; i < count; i++)
		std::cout << "Name: " << arr[i].name << ", age: " << arr[i].age << ", fn: " << arr[i].fn << std::endl;
	
	delete[] arr;
	
	return 0;
}
