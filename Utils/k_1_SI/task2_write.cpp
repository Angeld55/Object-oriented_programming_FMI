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

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool areAllLowerCase(const char* str)
{
	while(*str)
	{
		if(!isLower(*str))
			return false;
		str++;
	}
	return true;
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isNameValid(const char* name)
{
	size_t len = strlen(name);
	if(len == 0 || len > MAX_NAME_SIZE)
		return false;
	return isUpper(*name) && areAllLowerCase(name + 1);
}

void initStudent(Student& st, const char* name, size_t fn, bool isMale)
{
    if(!isNameValid(name))
        strcpy(st.name, "Unknown");
    else
        strcpy(st.name, name);

    st.isMale = isMale; 
    st.fn = fn;
}

void saveToFile(const Student* students, size_t count, ofstream& file)
{
	file.write((const char*)students, count * sizeof(Student));
}


int main()
{
    const size_t studentsCount = 4;
	Student* arr = new Student[studentsCount];
	initStudent(arr[0], "Ivan", 1, true);
	initStudent(arr[1], "Petur", 2, true);
	initStudent(arr[2], "Alex", 3, true);
	initStudent(arr[3], "Katerina", 4, false);

	ofstream file("students.dat", ios::binary);
		
	if(!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		delete[] arr; //!
		return -1;
	}
		
	saveToFile(arr, studentsCount, file);
	
	delete[] arr;
	
	return 0;
}
