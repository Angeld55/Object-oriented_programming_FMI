#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;


struct Student
{
	char* name;
	int age;
	int fn;
};

void saveStudent(ofstream& file, const Student& st)
{
	size_t nameLen = strlen(st.name) + 1;
	file.write((const char*)&nameLen, sizeof(nameLen));
	file.write(st.name, nameLen);
	file.write((const char*)&st.age, sizeof(st.age));
	file.write((const char*)&st.fn, sizeof(st.fn));
}

void loadStudent(ifstream& file, Student& st)
{
	size_t nameLen;
	file.read((char*)&nameLen, sizeof(nameLen));

	st.name = new char[nameLen];
	file.read(st.name, nameLen);

	file.read((char*)&st.age, sizeof(st.age));
	file.read((char*)&st.fn, sizeof(st.fn));

}

int main()
{

	{ //writing students to binary file

		Student s1;
		s1.name = new char[5];
		strcpy(s1.name, "ivan");
		s1.fn = 9999;
		s1.age = 30;


		Student s2;
		s2.name = new char[6];
		strcpy(s2.name, "angel");
		s2.fn = 5555;
		s2.age = 50;

		ofstream file("Students.dat", ios::binary);
		
		if (!file.open())
		{
			cout << "Error while writing to binary file!" << endl;
			delete[] s1.name, s2.name;
			return -1;
		}
		
		saveStudent(file, s1);
		saveStudent(file, s2);

		delete[] s1.name, s2.name;
	}

	{
		ifstream file("Students.dat", ios::binary);
		
		if (!file.open())
		{
			cout << "Error while reading from file!" << endl;
			return -1;
		}
		
		Student s1, s2;

		loadStudent(file, s1);
		loadStudent(file, s2);
		std::cout << s1.name << " " << s1.age << " " << s1.fn << std::endl;
		std::cout << s2.name << " " << s2.age << " " << s2.fn << std::endl;

		delete[] s1.name, s2.name;
	}



	


}
