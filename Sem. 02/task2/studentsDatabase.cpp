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
	int fn = 0;

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
	ind++;

	//fn
	while (input[ind] != '\0')
		(student.fn *= 10) += (input[ind++] - '0');
	
}

bool saveStudentsToFile(const OOPstudent* studentsCollection, int len, const char* fileName)
{
	ofstream outFile(fileName);

	if (!outFile.is_open())
		return false;

	outFile << "First name, Last name, email, fn" << endl;

	for (int i = 0; i < len; i++)
		outFile << studentsCollection[i].firstName << "," << studentsCollection[i].lastName << "," << studentsCollection[i].email << "," << studentsCollection[i].fn << endl;

	outFile.close();

	return true;
}

int indexOfFirstSpaceOrTerminatingZero(const char* command)
{
	int ind = 0;
	while (*command != ' ' && *command != '\t' && *command != '\0')
	{
		command++;
		ind++;
	}
	return ind;

}

bool printStudent(const OOPstudent* arrayOfStudents, int len,  int fn)
{
	for (int i = 0; i < len; i++)
	{
		if (arrayOfStudents[i].fn == fn)
		{
			cout << arrayOfStudents[i].firstName << "," << arrayOfStudents[i].lastName << "," << arrayOfStudents[i].email << "," << arrayOfStudents[i].fn << endl;
			return true;
		}
	}
	return false;
}
bool editFirstName(OOPstudent* arrayOfStudents, int len, int fn, const char* newFirstName)
{
	for (int i = 0; i < len; i++)
	{
		if (arrayOfStudents[i].fn == fn)
		{
			strcpy(arrayOfStudents[i].firstName, newFirstName);
			return true; //success!
		}
	}
	return false; //no such student
}
int main()
{

	cout << "Open file:" << endl << ">";

	char fileName[BUFFER_LINE_SIZE];
	cin.getline(fileName, BUFFER_LINE_SIZE);
		
	int studentsCount = countLines(fileName) - 1; // We ignore the first line 


	if (studentsCount <= 0)
	{
		cout << "Error while reading data from the file " << endl;
		return -1;
	}

	OOPstudent* studentsCollection = new OOPstudent[studentsCount];


	ifstream f(fileName, ios::_Nocreate);

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

	cout << "File successfully opened!" << endl;

	char commandLine[BUFFER_LINE_SIZE];
	do
	{
		cout << ">";
		cin.getline(commandLine, 1024);
		size_t len = strlen(commandLine);



		//first argument (edit, save ...)
		size_t firstArgSize = indexOfFirstSpaceOrTerminatingZero(commandLine);
		char* commandFirstArg = new char[firstArgSize + 1];

		for (int i = 0; i < firstArgSize; i++)
			commandFirstArg[i] = commandLine[i];
		commandFirstArg[firstArgSize] = '\0';


	

		if (len == firstArgSize) //no more arguments - quit? Check is bellow
			continue;

		//second argument (students.csv, 45543 ...)
		size_t secondArgSize = len - firstArgSize - 1;
		char* commandSecondArg = new char[secondArgSize + 1];

		for (int i = 0; i < secondArgSize; i++)
			commandSecondArg[i] = commandLine[firstArgSize + 1 + i];
		commandSecondArg[secondArgSize] = '\0';
		if (strcmp(commandFirstArg, "print") == 0)
		{
			int fn = atoi(commandSecondArg);

			bool res = printStudent(studentsCollection, studentsCount, fn);

			if (!res)
				cout << "Student with fn: " << fn << " doesn't exist!" << endl;;
		}
		else if (strcmp(commandFirstArg, "edit") == 0)
		{
			int fn = atoi(commandSecondArg);

			//we have a third argument here. It's in the second arguments string

			size_t seprator = indexOfFirstSpaceOrTerminatingZero(commandSecondArg);

			size_t thirdArgumentSize = secondArgSize - seprator;
			char* commandThirdArg = new char[thirdArgumentSize + 1];
			
			for (int i = 0; i < thirdArgumentSize; i++)
				commandThirdArg[i] = commandSecondArg[seprator + 1 + i];
			commandThirdArg[thirdArgumentSize] = '\0';

			bool result = editFirstName(studentsCollection, studentsCount, fn, commandThirdArg);

			if (result)
				cout << "Succesfully changed name!" << endl;
			else
				cout << "Student with fn: " << fn << "doesn't exist!" << endl;

			delete[] commandThirdArg;
		}
		else if (strcmp(commandFirstArg, "save") == 0)
		{

			bool res = saveStudentsToFile(studentsCollection, studentsCount, commandSecondArg);

			if (res)
				cout << "Successfully saved to file: " << commandSecondArg << endl;
			else
				cout << "Error while saving in file: " << commandSecondArg << endl;

		}
		delete[] commandFirstArg;
		delete[] commandSecondArg;

	} while (strcmp(commandLine, "Quit"));

	delete[] studentsCollection;
	return 0;
}
