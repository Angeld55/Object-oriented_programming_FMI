#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 1024;
int main()
{
	ifstream inputFile("selfPrintingTask.cpp");
	
	if (inputFile.fail())
	{
		cout << "Error!" << endl;
		return -1;
	}
	
	while (!inputFile.eof())
	{
		char buff[MAX_SIZE];
		inputFile.getline(buff, MAX_SIZE);
		cout << buff << endl;
	}
        inputFile.close()

	return 0;
}
