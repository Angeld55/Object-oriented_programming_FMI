#include <iostream>
#include <fstream>
using namespace std;


bool copyFile(const char* source, const char* dest)
{
	ifstream inputFile(source);
	ofstream outputFile(dest, ios::app);

	if (!inputFile.is_open() || !outputFile.is_open())
		return false;

	while (!inputFile.eof())
	{
		char line[1024];
		inputFile.getline(line, 1024);
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}



int main()
{
	if (copyFile("Source.cpp", "AnotherSource.cpp"))
	{
		std::cout << "Succesfully copied!";
	}
	else
	{
		std::cout << "Error while copying!";
	}

}
