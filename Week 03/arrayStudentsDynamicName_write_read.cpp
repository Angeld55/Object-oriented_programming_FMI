#include <iostream>
#include <fstream>
#include <cstring>
 
#pragma warning( disable : 4996)
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
 
void printStudent(const DynamicNameStudent& st)
{
	std::cout << st.name << " " << st.age << " " << st.fn << std::endl;
}
 
void saveStudentsArrayToFile(std::ofstream& ofs,
	const DynamicNameStudent* arr,
	size_t arraySize)
{
	ofs.write((const char*)&arraySize, sizeof(arraySize));
 
	for (size_t i = 0; i < arraySize; i++)
		saveToBinaryFile(ofs, arr[i]);
}
 
void readStudents(std::ifstream& ifs, DynamicNameStudent*& ptr, size_t& size)
{
	ifs.read((char*)&size, sizeof(size));
 
	ptr = new DynamicNameStudent[size];
 
	for (size_t i = 0; i < size; i++)
		ptr[i] = readFromBinaryFile(ifs);
}
 
int main()
{
 
	{
		std::ofstream ofs("arrStudents.dat", std::ios::out | std::ios::binary);
		if (!ofs.is_open())
			return -1;
 
		DynamicNameStudent arr[3];
		arr[0] = init("Ivan", 10, 20);
		arr[1] = init("Peter", 41, 44);
		arr[2] = init("Nikolay", 99, 0);
 
		saveStudentsArrayToFile(ofs, arr, 3);
 
		freeStudent(arr[0]);
		freeStudent(arr[1]);
		freeStudent(arr[2]);
	}
 
 
	{
		std::ifstream ifs("arrStudents.dat", std::ios::in | std::ios::binary);
		if (!ifs.is_open())
			return -1;
		DynamicNameStudent* arr;
		size_t size;
 
		readStudents(ifs, arr, size);
 
		for (size_t i = 0; i < size; i++)
			printStudent(arr[i]);
 
		for (size_t i = 0; i < size; i++)
			freeStudent(arr[i]);
	}
}
