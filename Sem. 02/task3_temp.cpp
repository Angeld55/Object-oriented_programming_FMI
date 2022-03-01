#include <iostream>
#include <fstream>
using namespace std;


const size_t capacity = 1024;

enum class Spec
{
	computerScience,
	softEng
};
struct StudentRecord
{
	char firstName[capacity];
	char lastName[capacity];
	char fnRaw[capacity];

	Spec spec;
	int fn;

	char email[capacity];
};

struct StudentCollection
{
	StudentRecord* data;
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

	file.close ();

	return count;

}

int main()
{
	
	char inputFileName[] = "lists/si.csv";
	size_t studentsCount = getLinesCount(inputFileName) - 1;

	StudentCollection myCollection;
	myCollection.data = new StudentRecord[studentsCount];


	//parse
	//...



	delete[] myCollection.data;

}
