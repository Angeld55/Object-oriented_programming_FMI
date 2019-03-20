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

	test obj1{ 'a', 4 };
	test obj2{ 'b', 5 };
	test obj3{ 'c', 6 };

	ofstream outF("Structs.bat", ios::binary);

	if (!outF.is_open())
	{
		cout << "Error while opening file"<<endl;
		return 1;
	}
	
	//запазваме 3-те обекта във файла
	outF.write((const char*)&obj1, sizeof(test));
	outF.write((const char*)&obj2, sizeof(test));
	outF.write((const char*)&obj3, sizeof(test));

	if (!outF.good()) // проверяваме дали след операцията потокът е в невалидено състояние
	{
		cout<<"Error occurred while writing the file";
		return 1;
	}
	
	outF.close();

	return 0;
}