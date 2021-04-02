#include <iostream>
#include<cstring>
#include<fstream>
#pragma warning(disable : 4996)

struct Student 
{
	char* name;
	int fn;
	int gradesCount;
	double averageGrade;
};

struct University 
{
	char name[32];
	Student* collection;
	size_t studentsCount;
};

void print(const Student& st) 
{
	std::cout << std::endl << "======STUDENT======" << std::endl;
	std::cout << "Name: " << st.name << std::endl << "Faculcy number:" << st.fn <<
		std::endl << "Grades: " << st.gradesCount << std::endl << "Avarage: " << st.averageGrade << std::endl;
}

Student createStudent(const char* name, int fn, int gradesCount, double avGrade) 
{
	Student obj;

	size_t nameLen = strlen(name);

	obj.name = new char[nameLen + 1];
	strcpy(obj.name, name);

	obj.fn = fn;
	obj.gradesCount = gradesCount;
	obj.averageGrade = avGrade;

	return obj;
}

void freeStudent(Student& s) 
{
	delete[] s.name;

	s.averageGrade = s.fn = s.gradesCount = 0;

}

void saveStudentToFile(std::ofstream& f, const Student& st) 
{
	size_t nameLen = strlen(st.name);

	f.write((const char*)&nameLen, sizeof(nameLen));  //first we write the size of the name!
	f.write(st.name, nameLen);

	f.write((const char*)&st.fn, sizeof(st.fn));
	f.write((const char*)&st.gradesCount, sizeof(st.gradesCount));
	f.write((const char*)&st.averageGrade, sizeof(st.averageGrade));
}

Student readStudentFromFile(std::ifstream& f) 
{
	Student res;

	size_t nameLen;

	f.read((char*)&nameLen, sizeof(nameLen)); //first we read the size of the name!

	res.name = new char[nameLen + 1];
	f.read(res.name, nameLen);
	res.name[nameLen] = '\0';

	f.read((char*)&res.fn, sizeof(res.fn));
	f.read((char*)&res.gradesCount, sizeof(res.gradesCount));
	f.read((char*)&res.averageGrade, sizeof(res.averageGrade));

	return res;
}

University createUniversity(const char* _name, const Student* collection, const size_t& studentCount) 
{
	University uni;

	strcpy(uni.name, _name);
	uni.collection = new Student[studentCount];
	uni.studentsCount = studentCount;

	for (size_t i = 0; i < studentCount; i++) 
	{
		uni.collection[i] = collection[i];
	}

	return uni;
}

void saveUniversityToFile(std::ofstream& outStream, const University& Uni) 
{
	//Writing the name of the university first:
	outStream.write(Uni.name, 32);

	//Then we write the students count:
	outStream.write((const char*)(&Uni.studentsCount), sizeof(Uni.studentsCount));

	//Writing every single student:
	size_t count = Uni.studentsCount;
	for (size_t i = 0; i < count; i++) 
	{
		saveStudentToFile(outStream, Uni.collection[i]);
	}
}

University readUniFromFile(std::ifstream& inFile) 
{
	//to return:
	University uni;

	//We follow the same read order as we wrote them:

	//name:
	inFile.read((char*)(&uni.name), 32);

	//count:
	inFile.read((char*)(&uni.studentsCount), sizeof(uni.studentsCount));

	//students:
	size_t studentsCount = uni.studentsCount;
	uni.collection = new Student[studentsCount];

	for (size_t i = 0; i < studentsCount; i++) 
	{
		uni.collection[i] = readStudentFromFile(inFile);
	}

	return uni;
}

void printUni(const University& uni) 
{
	size_t studentsCount = uni.studentsCount;

	std::cout << std::endl << "----------" << uni.name << "----------";

	for (size_t i = 0; i < studentsCount; i++)
	{
		print(uni.collection[i]);
		std::cout << std::endl;
	}
	std::cout << "-------------------------";
}

void freeUni(University& uni) 
{
	for (int i = 0; i < uni.studentsCount; i++)
		freeStudent(uni.collection[i]);

	strcpy(uni.name, "");
	uni.studentsCount = 0;
}

void changeStudentName(Student& st, const char* newName)
{
	delete[] st.name;
	st.name = new char[strlen(newName) + 1];
	strcpy(st.name, newName);
}

void changeName(University* uniCollection, const int& uniCount, const char* uni, const int& fn, const char* newName) 
{
	int uniFound = -1;
	int studentFound = -1;

	for (int i = 0; i < uniCount; i++) 
	{
		if (strcmp(uniCollection[i].name, uni) != 0) 
		{
			continue;
		}


		uniFound = i;
		size_t studentsCount = uniCollection[i].studentsCount;

		for (size_t j = 0; j < studentsCount; j++) 
		{
			if (uniCollection[i].collection[j].fn != fn)
			{
				continue;
			}

			studentFound = j;
			changeStudentName(uniCollection[i].collection[j], newName);
			break;
		}
		break;
	}

	if (uniFound != -1 && studentFound != -1) 
	{
		std::cout << std::endl << "Changed: " << std::endl;
		print(uniCollection[uniFound].collection[studentFound]);
	}
	else 
	{
		std::cout << std::endl << "No such student in this university" << std::endl;
	}
}

void addStudentGrade(Student& st, const int& grade)
{
	double newAvarageGrade = (double)((st.averageGrade * st.gradesCount) + grade) / (double)(st.gradesCount + 1);
	st.averageGrade = newAvarageGrade;
	st.gradesCount++;
}

void addGrade(University* uniCollection, const int& uniCount, const char* uni, const int& fn, const int& grade) 
{
	int uniFound = -1;
	int studentFound = -1;

	for (int i = 0; i < uniCount; i++)
	{
		if (strcmp(uniCollection[i].name, uni) != 0) 
		{
			continue;
		}

		uniFound = i;
		size_t studentsCount = uniCollection[i].studentsCount;

		for (size_t j = 0; j < studentsCount; j++) 
		{
			if (uniCollection[i].collection[j].fn != fn)
			{
				continue;
			}

			studentFound = j;
			addStudentGrade(uniCollection[i].collection[j], grade);
			break;
		}
		break;
	}

	if (uniFound != -1 && studentFound != -1) 
	{
		std::cout << std::endl << "Added: " << std::endl;
		print(uniCollection[uniFound].collection[studentFound]);
	}
	else
	{
		std::cout << std::endl << "No such student in this university" << std::endl;
	}
}

double getSuccess(const University uni) 
{
	double avarageGrade = 0;
	size_t studentsCount = uni.studentsCount;

	for (size_t i = 0; i < studentsCount; i++) 
	{
		avarageGrade += uni.collection[i].averageGrade;
	}

	avarageGrade = avarageGrade / (double)(studentsCount);

	return avarageGrade;
}

void swapUniversities(University* uniCollection, const int& first, const int& second) 
{
	University temp = uniCollection[first];
	uniCollection[first] = uniCollection[second];
	uniCollection[second] = temp;
}

void sort(University* uniCollection, size_t unisCount) 
{
	//selection sort
	for (int pos = 0; pos < unisCount - 1; pos++) 
	{
		int minimalIndex = pos;
		
		for (int i = pos; i < unisCount; i++) 
		{
			int currSuccess = getSuccess(uniCollection[minimalIndex]);
			if (getSuccess(uniCollection[i]) > currSuccess) 
			{
				minimalIndex = i;
			}
		}

		if (minimalIndex != pos)
			swapUniversities(uniCollection, pos, minimalIndex);
	}
}

int main() 
{
	//simple example:

	//creating university database:---------------
	University* uniCollection = new University[3];

	//FMI
	Student collection[3];
	collection[0] = createStudent("Angel", 81111, 6, 3);
	collection[1] = createStudent("Dimitar", 82222, 6, 2);
	collection[2] = createStudent("Anton", 83333, 6, 2);

	University FMI = createUniversity("FMI", collection, 3);

	//TU
	Student collectionTwo[4];
	collectionTwo[0] = createStudent("Vesko", 31244, 6, 6);
	collectionTwo[1] = createStudent("Ivan", 42342, 6, 6);
	collectionTwo[2] = createStudent("Mariano", 13433, 6, 6);
	collectionTwo[3] = createStudent("Gabriela", 43234, 6, 6);

	University TU = createUniversity("TU", collectionTwo, 4);

	//UNWE
	Student collectionThree[5];
	collectionThree[0] = createStudent("Chavdar", 13579, 6, 4);
	collectionThree[1] = createStudent("Stoino", 24680, 6, 4);
	collectionThree[2] = createStudent("Miss Playmate", 24567, 6, 4);
	collectionThree[3] = createStudent("ex fmi student", 12343, 6, 4);
	collectionThree[4] = createStudent("bukvalno vseki", 13333, 6, 5);

	University UNWE = createUniversity("UNWE", collectionThree, 5);

	uniCollection[0] = FMI;
	uniCollection[1] = TU;
	uniCollection[2] = UNWE;
	//-------------------------------------------------------------

	//functions:
	std::ofstream outFile("path.txt", std::ios::binary);
	saveUniversityToFile(outFile, uniCollection[1]);
	if (outFile.good() == 0)
	{
		std::cout << "Error saving the file";
	}

	outFile.close();

	std::ifstream inFile("path.txt", std::ios::binary);
	University example = readUniFromFile(inFile);

	if (inFile.good() == 0) 
	{
		std::cout << "Error reading the file";
	}

	inFile.close();

	printUni(example);

	changeName(uniCollection, 3, "FMI", 83333, "Antoan");
	addGrade(uniCollection, 3, "FMI", 81111, 6);

	sort(uniCollection, 3);

	std::cout << "\nSorted:\n";

	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << ". " << uniCollection[i].name << std::endl;
	}

	for (int i = 0; i < 3; i++) 
	{
		freeUni(uniCollection[i]);
	}
}
