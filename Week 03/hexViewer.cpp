#include <iostream>
#include <fstream>
#include <iomanip>

struct HexViewerFile
{
	unsigned char* data;
	size_t dataSize;
};
size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}
HexViewerFile init(const char* str)
{
	std::ifstream ifs(str, std::ios::in | std::ios::binary);
	HexViewerFile myFile;

	if(!ifs.is_open())
	{
	    myFile.data = nullptr;
	    myFile.dataSize = 0;
	    return myFile;
	}    

	myFile.dataSize = getFileSize(ifs);
	myFile.data = new unsigned char[myFile.dataSize];
	ifs.read((char*)myFile.data, myFile.dataSize);
    
    ifs.close();
	return myFile;
}

void freeHexViewerFile(HexViewerFile& file)
{
	delete[] file.data;
	file.dataSize = 0;
}


bool isValidSymbol(unsigned char ch)
{
	return ch >= 'a' && ch <= 'z' ||
		   ch >= 'A' && ch <= 'Z' ||
		   ch >= '0' && ch <= '9';
}
void print(const HexViewerFile& myFile)
{
	for (int i = 0; i < myFile.dataSize; i++)
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)myFile.data[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < myFile.dataSize; i++)
	{
		if (isValidSymbol(myFile.data[i]))
			std::cout << myFile.data[i] << "  ";
		else
			std::cout << ".. ";
	}
	std::cout << std::endl;
}

int main()
{
	HexViewerFile myFile = init("student.dat");
	print(myFile);
	freeHexViewerFile(myFile);
}
