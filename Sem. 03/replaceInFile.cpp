#include <iostream>
#include <fstream>
using namespace std;

void replaceInFile(char ch, char ch2, fstream& file)
{
	while (!file.eof())
	{
		char currentSybmol = file.get();

		if (currentSybmol != ch)
			continue;

		file.seekp(-1, ios::cur);
		file.put(ch2);
		file.flush();
	}
}

int main()
{
	fstream file("treasureTrail.txt", ios::in | ios::out);
	replaceInFile('a', 'X', file);
}
