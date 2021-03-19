#include <iostream>
#include <fstream>

using namespace std;


struct Student
{
	char* name;
	int fn;
	int gradesCount;
	double averageGrade;
};
void print(const Student& st)
{
	cout << st.name << " " << st.fn << " " << st.gradesCount << " " << st.averageGrade << endl;
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
void saveStudentToFile(ofstream& f, const Student& st)
{
	size_t nameLen = strlen(st.name);
	f.write((const char*)&nameLen, sizeof(nameLen));  //first we write the size of the name!
	f.write(st.name, nameLen);
	f.write((const char*)&st.fn, sizeof(st.fn));
	f.write((const char*)&st.gradesCount, sizeof(st.gradesCount));
	f.write((const char*)&st.averageGrade, sizeof(st.averageGrade));

}
Student readStudentFromFile(ifstream& f)
{
	Student res;

	size_t nameLen;

	f.read((char *)&nameLen, sizeof(nameLen));  //first we read the size of the name!

	res.name = new char[nameLen + 1];
	f.read(res.name, nameLen);
	res.name[nameLen] = '\0';

	f.read((char *)&res.fn, sizeof(res.fn));
	f.read((char*)&res.gradesCount, sizeof(res.gradesCount));
	f.read((char*)&res.averageGrade, sizeof(res.averageGrade));

	return res;
}
void freeStudent(Student& s)
{
	delete[] s.name;

	s.averageGrade = s.fn = s.gradesCount = 0;

}

const int UNI_NAME_MAX = 32;
struct Uni
{
	char name[UNI_NAME_MAX];
	size_t studentsCount;
	Student* students;
};

void saveUniToFile(ofstream& f, const Uni& uni)
{
	
	f.write(uni.name, sizeof(uni.name));
	f.write((const char*)&uni.studentsCount, sizeof(uni.studentsCount));  //first we write how many students we have!
	
	for (int i = 0; i < uni.studentsCount; i++)
		saveStudentToFile(f, uni.students[i]);
}

void readUniFromFile(ifstream& f, Uni& uni)
{
	f.read(uni.name, sizeof(uni.name));
	f.read((char*) &uni.studentsCount, sizeof(uni.studentsCount));  //we read how many students are saved in the file!

	uni.students = new Student[uni.studentsCount];
	
	for (int i = 0; i < uni.studentsCount; i++)
		uni.students[i] = readStudentFromFile(f);
}
void freeUni(Uni& uni)
{
	for (int i = 0; i < uni.studentsCount; i++)
		freeStudent(uni.students[i]);
	strcpy(uni.name, "");
	uni.studentsCount = 0;
}
void print(const Uni&  u)
{
	cout << u.name << " " << u.studentsCount << endl;
	for (int i = 0; i < u.studentsCount; i++)
		print(u.students[i]);
}
int main()
{
	{ //Creating an university and saving to file
		Uni u;
		strcpy(u.name, "FMI");
		u.studentsCount = 3;

		u.students = new Student[u.studentsCount];
		u.students[0] = createStudent("Ivan", 81234, 3, 4.5);
		u.students[1] = createStudent("Angel", 12345, 4, 5);
		u.students[2] = createStudent("Mariq", 81234, 5, 5.5);


		ofstream f("uni.dat", ios::binary);

		if (!f.is_open())
		{
			cout << "Error" << endl;
			return -1;
		}

		saveUniToFile(f, u);
		freeUni(u);
	}

	{ //Reading an university from file
		
		Uni myUni;
		ifstream f("uni.dat", ios::binary);

		if (!f.is_open())
		{
			cout << "Error" << endl;
			return -1;
		}

		readUniFromFile(f, myUni);

		print(myUni);

		f.close();

		freeUni(myUni);

	}
}
 
