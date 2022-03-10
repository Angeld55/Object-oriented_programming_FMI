#include <iostream>
#include <fstream>
#include <cstring> 
#pragma warning(disable:4996)
using namespace std;

const size_t capacity = 1024;

enum class Speciality
{
	computerScience,
	softwareEngineering
};

struct StudentRecord
{
	char firstName[capacity];
	char lastName[capacity];

	char fnRaw[capacity];

	//parsed by fnRaw
	Speciality studentSpeciality;
	int fn;
	//

	char email[capacity];
};

struct StudentCollection
{
	StudentRecord* data;
	size_t studentsCount;
};

size_t getLinesCount(const char* fileName)
{
	ifstream file(fileName);

	if (!file.is_open())
		return 0;

	size_t count = 0;

	while (!file.eof())
	{
		char buff[capacity];
		file.getline(buff, capacity);
		count++;
	}

	file.close();

	return count;

}

void parseField(char* dest, const char*& source)
{
	while (*source != ',' && *source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	source++;
	*dest = '\0';
}

void parseFn(StudentRecord& currentStudent)
{
	if (strlen(currentStudent.fnRaw) < 5)
		return;

	if (currentStudent.fnRaw[4] == '6')
		currentStudent.studentSpeciality = Speciality::softwareEngineering;
	else if (currentStudent.fnRaw[4] == '8')
		currentStudent.studentSpeciality = Speciality::computerScience;

	currentStudent.fn = atoi(currentStudent.fnRaw + 5);

}

void parseStudent(StudentRecord& currentStudent, const char* line)
{
	parseField(currentStudent.firstName, line);
	parseField(currentStudent.lastName, line);
	parseField(currentStudent.fnRaw, line);
	parseField(currentStudent.email, line);
	parseFn(currentStudent);
}

void printStudent(const StudentRecord& st)
{
	std::cout << "First name: " << st.firstName << ", second name: " << st.lastName << ", speciality: ";

	if (st.studentSpeciality == Speciality::computerScience)
		std::cout << "computer science, ";
	else
		std::cout << "software engineering, ";

	std::cout << "number: " << st.fn << ", email: " << st.email << std::endl;

}

void initStudentCollection(StudentCollection& collection, const char* fileName)
{
	size_t linesCount = getLinesCount(fileName);
	
	size_t studentsCount = linesCount - 1;
	
	ifstream file(fileName);
	if (studentsCount == 0 || !file.is_open())
	{
		cout << "Error while reading from file!"  << std::endl;
		collection.studentsCount = 0;
		collection.data = nullptr;
		
		return;
	}
	
	collection.data = new StudentRecord[studentsCount];
	collection.studentsCount = studentsCount;

	char buff[capacity];
	file.getline(buff, capacity); ///skip the header
	for (int i = 0; i < studentsCount; i++)
	{
		file.getline(buff, capacity);
		parseStudent(collection.data[i], buff);
		
		printStudent(collection.data[i]);
	}
}

void saveToFile(const char* fileName, const StudentCollection& collection)
{
	ofstream file(fileName);
	if (!file.is_open())
		return;
	file << "Ime, Familiya, Fakulteten nomer, Imeyl adres" << std::endl; //header;
	for (int i = 0; i < collection.studentsCount; i++)
	{
	    file << collection.data[i].firstName << "," << collection.data[i].lastName << "," << collection.data[i].fnRaw << "," << collection.data[i].email;
        
        bool isLast = i == collection.studentsCount - 1;
        
        if(!isLast)
            file << std::endl;
	}
}
int main()
{
	const char* fileName = "students.txt";
	
	StudentCollection collection;
	initStudentCollection(collection, fileName);
	
	if(collection.studentsCount == 0)
	{
	    std::cout << "Error! No students loaded!" << std::endl;
	    return -1;
	}
	//changes to students email

	saveToFile(fileName, collection);
	delete[] collection.data;
	
	return 0;
}
