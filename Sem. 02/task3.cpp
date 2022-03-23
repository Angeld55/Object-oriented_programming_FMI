#include <iostream>
#include <fstream>
#include <cstring> 
#pragma warning(disable:4996)
using namespace std;

const size_t capacity = 1024;
const size_t bufferCapacity = 2.5 * capacity; // rough estimation of size of "edit fn Specialty email", where fn, Specialty and email are with their max width

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
	std::cout << "file " << fileName << " successfully saved!" << std::endl;
}

void accSubstr(const char*& raw, int& ind, char* output)
{
	for (int i = 0; raw[ind] != ' ' && raw[ind] != '\0'; i++, ind++)
	{
		output[i] = raw[ind];
		output[i + 1] = '\0';
	}
	ind++;
}

int studentIndByFNAndSpeciality(const StudentCollection& collection, int fn, Speciality speciality) {
	for (int i = 0; i < collection.studentsCount; i++)
		if (collection.data[i].fn == fn && collection.data[i].studentSpeciality == speciality)
			return i;

	std::cout << "Error: No student found!" << std::endl;
	return -1;
}

int studentIndByFNAndSpeciality(const StudentCollection& collection, const char* rawData, int& accInd)
{
	if (rawData[0] == ' ') accInd = 1;

	char fnBuffer[capacity];
	accSubstr(rawData, accInd, fnBuffer);

	int fn = atoi(fnBuffer);
	
	char specBuffer[capacity];
	accSubstr(rawData, accInd, specBuffer);

	Speciality speciality;
	if (strcmp(specBuffer, "SoftwareEngineering") == 0)
		speciality = Speciality::softwareEngineering;
	else if (strcmp(specBuffer, "ComputerScience") == 0)
		speciality = Speciality::computerScience;

	return studentIndByFNAndSpeciality(collection, fn, speciality);
}

int studentIndByFNAndSpeciality(const StudentCollection& collection, const char* rawData)
{
	int accInd = 0;
	return studentIndByFNAndSpeciality(collection, rawData, accInd);
}

void printStudentInCollectionFromRaw(const StudentCollection& collection, const char* rawData)
{
	int studentInd = studentIndByFNAndSpeciality(collection, rawData);
	if (studentInd < 0)
		return;

	printStudent(collection.data[studentInd]);
}

void editStudentEmailFromRaw(const StudentCollection& collection, const char* rawData)
{
	int accInd = 0, studentInd = studentIndByFNAndSpeciality(collection, rawData, accInd);
	if (studentInd < 0)
		return;

	char emailBuffer[capacity];
	accSubstr(rawData, accInd, emailBuffer);
	strcpy(collection.data[studentInd].email, emailBuffer);
}

int main()
{
	std::cout << "Open file:" << std::endl;

	char buffer[bufferCapacity];
	std::cin.getline(buffer, bufferCapacity);

	StudentCollection collection;
	initStudentCollection(collection, buffer);
	
	if(collection.studentsCount == 0)
	{
	    std::cout << "Error! No students loaded!" << std::endl;
	    return -1;
	}
	std::cout << "File successfully opened!" << std::endl;

	do
	{
		std::cin >> buffer;
		if (strcmp(buffer, "print") == 0)
		{
			std::cin.getline(buffer, bufferCapacity);
			std::cout << buffer << std::endl;
			printStudentInCollectionFromRaw(collection, buffer);
		}
		else if (strcmp(buffer, "edit") == 0)
		{
			std::cin.ignore();
			std::cin.getline(buffer, bufferCapacity);
			editStudentEmailFromRaw(collection, buffer);
		}
		else if (strcmp(buffer, "save") == 0)
		{
			std::cin >> buffer;
			saveToFile(buffer, collection);
			break;
		}
	} while(true);

	delete[] collection.data;
	
	return 0;
}
