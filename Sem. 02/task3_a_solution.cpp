#include <iostream> // cin, cout
#include <fstream>  // ifstream, ofstream
#include <cstring>  // strcmp

const int LINE_BUFFER_SIZE = 1024;
const int MAX_STUDENT_PROP_SIZE = LINE_BUFFER_SIZE;

/* Student */

struct Student
{
	char FirstName[MAX_STUDENT_PROP_SIZE];
	char LastName[MAX_STUDENT_PROP_SIZE];
	char Email[MAX_STUDENT_PROP_SIZE];
	char FN[MAX_STUDENT_PROP_SIZE];
};

void printStudent(const Student& st)
{
	std::cout << "Name = " << st.FirstName << " " << st.LastName << ", Email: " << st.Email << ", FN: " << st.FN << std::endl; 
}

Student parseStudent(const char* studentStr)
{
	Student toRet = {};
	char* prop = toRet.FirstName;

	for (int i = 0, j = 0; studentStr[i] != '\0'; i++)
	{
		if (studentStr[i] == ',')
		{
			if      (prop == toRet.FirstName) prop = toRet.LastName;
			else if (prop == toRet.LastName)  prop = toRet.Email;
			else if (prop == toRet.Email)     prop = toRet.FN;
			j = 0;
		}
		else prop[j++] = studentStr[i];
	}
	return toRet;
}

/* StudentsList */

struct StudentsList
{
	Student* students;
	int count;
	int length;
};

bool resizeStudentsList(StudentsList& sl, int newSize)
{
	if (newSize < sl.count) // We cant fit all of the old students in the new students array
		return false;

	Student* temp = new Student[newSize];
	for (int i = 0; i < sl.count; i++)
		temp[i] = sl.students[i];

	delete[] sl.students;
	sl.students = temp;

	return true;
}

void addStudent(StudentsList& sl, const Student& st)
{
	if (sl.count == sl.length)
		resizeStudentsList(sl, (sl.length == 0) ? sl.length = 2 : sl.length <<= 1);

	sl.students[sl.count++] = st;
}

int findStudentIndByFN(const StudentsList& sl, const char* FN)
{
	for (int i = 0; i < sl.count; i++)
		if (!strcmp(sl.students[i].FN, FN))
			return i;

	std::cout << "Error: No student found with FN of " << FN << "!" << std::endl;
	return -1;
}

StudentsList getStudentsListFromFile(const char* filePath)
{
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		std::cout << "Error: Could not open file " << filePath << "!" << std::endl;
		return {};
	}

	StudentsList sl = {};

	char buffer[LINE_BUFFER_SIZE];
	while (!inFile.eof())
	{
		inFile.getline(buffer, LINE_BUFFER_SIZE);
		if (buffer[0] != '\0')
			addStudent(sl, parseStudent(buffer));
	}

	inFile.close();
	return sl;
}

/* Commands */

// The buffer could get dirty with leftover data, so we check only if the beginning matches
bool isCommand(const char* inputBuffer, const char* command)
{
	for (int i = 0; command[i] != '\0'; i++)
		if (inputBuffer[i] != command[i])
			return false;

	return true;
}

void printStudentByFN(const StudentsList& sl, const char* FN)
{
	int stInd = findStudentIndByFN(sl, FN);
	if (stInd >= 0)
		printStudent(sl.students[stInd]);
}

void replaceStudentEmail(const StudentsList& sl, const char* FN, const char* newEmail)
{
	int stdInd = findStudentIndByFN(sl, FN);
	if (stdInd < 0)
		return; // findStudentIndByFN would have already written an error message, so we won't write one here

	Student& st = sl.students[stdInd];
	for (int i = 0; st.Email[i] != '\0' || newEmail[i] != '\0'; i++)
		st.Email[i] = (newEmail[i] == '\0') ? '\0' : newEmail[i];
}

void saveToFile(const StudentsList& sl, const char* newFilePath)
{
	std::ofstream newFile(newFilePath);
	if (!newFile.is_open())
	{
		std::cout << "Error: File " << newFilePath << " could not be opened!" << std::endl;
		return;
	}

	for (int i = 0; i < sl.count; i++)
	{
		Student st = sl.students[i];
		newFile << st.FirstName << "," << st.LastName << "," << st.Email << "," << st.FN << std::endl;
	}

	newFile.close();
}

/* Main */

int main()
{
	char inputBuffer[LINE_BUFFER_SIZE];
	std::cout << "Open file:" << std::endl << ">";
	std::cin >> inputBuffer;

	StudentsList readSL = getStudentsListFromFile(inputBuffer);
	if (readSL.students == nullptr)
		return -1;

	do
	{
		std::cout << ">";
		std::cin >> inputBuffer;

		if (isCommand(inputBuffer, "print"))
		{
			std::cin >> inputBuffer;
			printStudentByFN(readSL, inputBuffer);
		}
		else if (isCommand(inputBuffer, "edit"))
		{
			char tempFNBuffer[LINE_BUFFER_SIZE];
			std::cin >> tempFNBuffer >> inputBuffer;
			replaceStudentEmail(readSL, tempFNBuffer, inputBuffer);
		}
		else if (isCommand(inputBuffer, "save"))
		{
			std::cin >> inputBuffer;
			saveToFile(readSL, inputBuffer);
		}
	}
	while (!isCommand(inputBuffer, "end"));

	delete[] readSL.students;
}
