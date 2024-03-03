#include <iostream>
#include <fstream>

unsigned getCharCountFromFile(std::ifstream& ifs, char ch)
{
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open())
		return 0;

	unsigned int count = 0;

	while (true)
	{
		char current = ifs.get();
		if (ifs.eof())
			break;

		if (current == ch)
			count++;
	}

	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}

int* getArrayFromFile(const char* fileName, size_t& arraySize)
{
	std::ifstream stream(fileName);
	if (!stream.is_open())
		return nullptr;

	arraySize = getCharCountFromFile(stream, ' ') + 1;
	int* result = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		stream >> result[i];
	}

	stream.close();
	return result;
}

int* merge(const int* first, size_t firstSize, const int* second, size_t secondSize)
{
	size_t iterFirst = 0;
	size_t iterSecond = 0;

	int* merged = new int[firstSize + secondSize];
	size_t mergedIter = 0;

	while (iterFirst < firstSize && iterSecond < secondSize)
	{
		if (first[iterFirst] <= second[iterSecond])
			merged[mergedIter++] = first[iterFirst++];
		else
			merged[mergedIter++] = second[iterSecond++];
	}

	while (iterFirst < firstSize)
		merged[mergedIter++] = first[iterFirst++];

	while (iterSecond < secondSize)
		merged[mergedIter++] = second[iterSecond++];

	return merged;
}

void mergeFromFiles(const char* firstFileName, const char* secondFileName, const char* mergedFileName)
{
	size_t firstArraySize, secondArraySize;
	int* firstArray = getArrayFromFile(firstFileName, firstArraySize);
	if (!firstArray)
		return;
	int* secondArray = getArrayFromFile(secondFileName, secondArraySize);

	if (!secondArray)
	{
		delete[] firstArray;
		return;
	}

	int* result = merge(firstArray, firstArraySize, secondArray, secondArraySize);

	std::ofstream output(mergedFileName);

	if (!output.is_open())
	{
		delete[] firstArray;
		delete[] secondArray;
		delete[] result;
		return;
	}
	for (int i = 0; i < firstArraySize + secondArraySize; i++)
		output << result[i] << " ";

	delete[] firstArray;
	delete[] secondArray;
	delete[] result;

	output.close();
}

int main()
{
	mergeFromFiles("file1.txt", "file2.txt", "merged.txt");
}
