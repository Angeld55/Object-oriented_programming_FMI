#include <iostream>
#include <fstream>
using namespace std;

struct test
{
	char ch;
	int num;
};

int main()
{

	test arr[] = { { 'a', 4 }, { 'b', 5 }, { 'c', 6 } };

	ofstream outF("Structs.bat", ios::binary);

	if (!outF.is_open())
	{
		cout << "Error while opening file" << endl;
		return 1;
	}

	outF.write((const char*)&arr, sizeof(arr)); 
	//можем директно да запазим масива във файла. Резултатът ще същия като от SaveStructToBinaryFile.cpp
	

	if (!outF.good()) 
	{
		cout << "Error occurred while writing the file";
		return 1;
	}

	outF.close();

	return 0;
}