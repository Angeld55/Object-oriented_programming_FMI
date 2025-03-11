#include <iostream>
#include <fstream>
using namespace std;

void replaceInFile(char ch, char ch2, fstream& file)
{
	char currentSymbol;
	while (file.get(currentSymbol))
	{
	    if (currentSymbol == ch)
	    {
	        file.seekp(-1, std::ios::cur);
	        file.put(ch2);
	        file.flush();
	    }
	}
}

int main()
{
	fstream file("treasureTrail.txt", ios::in | ios::out);
	
			
	if(!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}
	
	replaceInFile('a', 'X', file);
	return 0;
}
