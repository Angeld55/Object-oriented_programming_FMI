#include <iostream>
#include <fstream>

void writeInBinFile(std::ofstream& ofs, const int* arr, unsigned size)
{
	ofs.write((const char*)arr, size * sizeof(int));
}

void writeInBinFile(const char* fileName, const int* arr, unsigned size)
{
	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open())
	{
		return;
	}

	writeInBinFile(ofs, arr, size);
}

unsigned fileSize(std::ifstream& ifs)
{
	unsigned curr = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	unsigned res = ifs.tellg();
	ifs.seekg(curr, std::ios::beg);
	ifs.clear();
	return res;
}

int* readFromBinFile(std::ifstream& ifs, unsigned& size)
{
	unsigned sizeOfFile = fileSize(ifs);
	size = sizeOfFile / sizeof(int);

	int* arr = new int[size];
	ifs.read((char*)arr, sizeOfFile);
	return arr;
}

int* readFromBinFile(const char* fileName, unsigned& size)
{
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open())
	{
		return nullptr;
	}

	return readFromBinFile(ifs, size);
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	writeInBinFile("number.dat", arr, 5);
	
	unsigned size;
	int* arr1 = readFromBinFile("number.dat", size);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr1[i] << ' ';
	}

	delete[] arr1;
}
