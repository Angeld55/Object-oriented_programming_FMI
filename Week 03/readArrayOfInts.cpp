#include <iostream>
#include <fstream>


size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

int main()
{
	std::ifstream ifs("myfile.dat", std::ios::in | std::ios::binary);

	size_t fileSize = getFileSize(ifs);
	size_t arrSize = fileSize / sizeof(int);
	int* arr = new int[arrSize];

	ifs.read((char*)arr, fileSize);

	for (int i = 0; i < arrSize; i++)
		std::cout << arr[i] << " ";

	delete[] arr;
	ifs.close();
}
