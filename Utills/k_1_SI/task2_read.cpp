#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const size_t MAX_NAME_SIZE = 22;
struct Student
{
	//gender should be BEFORE fn so the struct would be 28 bytes.
	char name[MAX_NAME_SIZE + 1];
   	bool isMale;
	size_t fn;
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
		std::cout << "Name: " << arr[i].name << ", fn: " << arr[i].fn << ", is male: " << arr[i].isMale << std::endl;
	
	delete[] arr;
	
	return 0;
}
