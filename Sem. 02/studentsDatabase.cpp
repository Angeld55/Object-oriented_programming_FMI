#include <iostream>
#include <fstream>

using namespace std;

const int FIELD_MAX_SIZE = 50;
const int BUFFER_LINE_SIZE = 1024;

struct OOPstudent
{
	char firstName[FIELD_MAX_SIZE];
	char lastName[FIELD_MAX_SIZE];
	char email[FIELD_MAX_SIZE];
	int fn;

};

int countLines(const char* fileName)
{
	ifstream f(fileName);
	if (!f.is_open())
		return -1;
	int linesCount = 0;

	while (!f.eof())
	{
		char buff[1024];
		f.getline(buff, 1024);
		linesCount++;
	}
	f.close();

	return linesCount;
	
}
// abc,bcd,ab@Abv.bg,fn
void readStudent(const char* input, OOPstudent& student)
{
	int ind = 0;

	// first name
	while (input[ind] != ',')
	{
		student.firstName[ind] = input[ind];
		ind++;
	}
	student.firstName[ind] = '\0';
	ind++;

	//last name
	int lastNameInd = 0;
	while (input[ind] != ',')
		student.lastName[lastNameInd++] = input[ind++];
	student.lastName[lastNameInd] = '\0';
	ind++;

	//email
	int emailInd = 0;

	while (input[ind] != ',')
		student.email[emailInd++] = input[ind++];
	student.email[emailInd] = '\0';

	//fn
	//??
}

void saveStudentsToFile(const OOPstudent* studentsCollection,int len,  const char* fileName)
{
	ofstream outFile(fileName);

	if (!outFile.is_open())
		return;

	for (int i = 0; i < len; i++)
		outFile << studentsCollection[i].firstName << " " << studentsCollection[i].lastName << " " << studentsCollection[i].email << endl;

	outFile.close();
}

int main()
{

	int studentsCount = countLines("students.csv") - 1; // We ignore the first line 

	OOPstudent* studentsCollection = new OOPstudent[studentsCount]; 

	ifstream f("students.csv");

	if (!f.is_open())
	{
		cout << "Error!" << endl;
		delete[] studentsCollection;
		return -1;
	}

	int line = 1;
	while (!f.eof())
	{
		char buff[BUFFER_LINE_SIZE];
		f.getline(buff, BUFFER_LINE_SIZE);

		if (line == 1)
		{
			line++;
			continue;
		}

		readStudent(buff, studentsCollection[line - 2]);
		line++;
	}
	f.close();


	//Do stuff

	saveStudentsToFile(studentsCollection, studentsCount, "result.txt");


	

	delete[] studentsCollection;
	return 0;
}