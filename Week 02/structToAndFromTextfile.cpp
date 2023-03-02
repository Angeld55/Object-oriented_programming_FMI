#include <iostream>
#include <fstream>

enum class major
{
	Se,
	Is,
	Cs,
	I
};

struct Student
{
	char name[1024];
	int age;
	major studentMajor;
};

void saveStudentToFile(std::ofstream& ofs, const Student& st)
{
	ofs << st.name << std::endl;
	ofs << st.age << std::endl;
	ofs << (int)st.studentMajor << std::endl;
}

void readStudentFromFile(std::ifstream& ifs, Student& st)
{
	ifs.getline(st.name, 1024);
	ifs >> st.age;
	ifs.ignore();
	int majorInt;
	ifs >> majorInt;
	st.studentMajor = (major)majorInt;
	ifs.ignore();
}

void writeArrayToFile(const char* fileName, const Student* students, size_t size)
{
	std::ofstream outputStream(fileName);
	if (!outputStream.is_open())
		return;
	outputStream << size << std::endl;

	for (unsigned i = 0; i < size; i++)
		saveStudentToFile(outputStream, students[i]);
}

Student* readArrayFromFile(const char* fileName, size_t& size)
{
	std::ifstream inputStream(fileName);

	if (!inputStream.is_open())
		return nullptr;
	
	inputStream >> size;
	inputStream.ignore();

	Student* result = new Student[size];

	for (unsigned int i = 0; i < size; i++)
		readStudentFromFile(inputStream, result[i]);
	return result;
}

int main()
{
	Student st[2] = { "Ivan", 34, major::Se,
					 "Petur", 20, major::Is };

	writeArrayToFile("students.txt", st, 2);

	size_t size;
	Student* result = readArrayFromFile("students.txt", size);

	for (int i = 0; i < size; i++)
		std::cout << result[i].name << " " << result[i].age <<" " << (int)result[i].studentMajor << std::endl;
}

