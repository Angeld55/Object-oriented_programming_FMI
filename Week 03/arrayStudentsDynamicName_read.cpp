#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

struct DynamicNameStudent
{
	char* name;
	int age;
	int fn;
};

DynamicNameStudent init(const char* name, int age, int fn)
{
	DynamicNameStudent st;

	st.name = new char[strlen(name) + 1];
	strcpy(st.name, name);

	st.age = age;
	st.fn = fn;

	return st;
}

void freeStudent(DynamicNameStudent& st)
{
	delete[] st.name;
	st.age = st.fn = 0;
}

void saveToBinaryFile(std::ofstream& ofs, const DynamicNameStudent& st)
{
	int nameLen = strlen(st.name);
	ofs.write((const char*)&nameLen, sizeof(int));
	ofs.write(st.name, nameLen + 1);

	ofs.write((const char*)&st.age, sizeof(st.age));
	ofs.write((const char*)&st.fn, sizeof(st.fn));

}
DynamicNameStudent readFromBinaryFile(std::ifstream& ifs)
{
	DynamicNameStudent st2;

	int nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	st2.name = new char[nameLen + 1];

	ifs.read(st2.name, nameLen + 1);

	ifs.read((char*)&st2.age, sizeof(st2.age));
	ifs.read((char*)&st2.fn, sizeof(st2.fn));

	return st2;
}



int main()
{
    {
		DynamicNameStudent myStudent = init("Ivan", 10, 30);

		std::ofstream ofs("student.dat", std::ios::out | std::ios::binary);

		saveToBinaryFile(ofs, myStudent);

		freeStudent(myStudent);
	}

	{
		std::ifstream ifs("student.dat", std::ios::in | std::ios::binary);
		DynamicNameStudent st = readFromBinaryFile(ifs);

		std::cout << st.name << " " << st.age << " " << st.fn;
	}
}
