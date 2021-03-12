#include <iostream>
#include <fstream>

using namespace std;

size_t getFileSize(const char* fileName)
{
	ifstream f(fileName);

	if (!f.is_open())
		return 0;

	f.seekg(0, ios::end);
	size_t pos = f.tellg();
	
	f.close();

	return pos;
}
int main()
{
	

	cout << getFileSize("sizeFile.cpp") << endl;

	return 0;
}