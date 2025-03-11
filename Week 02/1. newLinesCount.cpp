#include <iostream>
#include <fstream>
#include <assert.h>

const char NEW_LINE_CHAR = '\n';

int getCharCount(std::ifstream& ifs, char ch) 
{
    if (!ifs.is_open()) 
        return -1;

    int count = 0;
    char current;
    
    while (ifs.get(current)) 
    {
        if (current == ch) 
            ++count;
    }
    return count;
}

// we assume that the file have at least one symbol and that there is not an endline symbol at the end.
int getLinesCount(const char* fileName) {
	if (!fileName) 
		return -1;
	
	std::ifstream ifs(fileName);
	if (!ifs.is_open()) 
		return -1;

	return getCharCount(ifs, NEW_LINE_CHAR) + 1;
}
int main()
{
	std::cout << getLinesCount("file.txt");
}
