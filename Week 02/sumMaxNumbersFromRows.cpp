#include <iostream>
#include <sstream>
#include <fstream>


int getMaxNumberFromString(const char* str)
{
	std::stringstream ss(str);

	int max = INT_MIN;
	while (!ss.eof())
	{
		int current;
		ss >> current;
		if (current > max)
			max = current;
	}
	return max;
}
int sumMaxNumbersFromEachRow(const char* fileName)
{
	std::ifstream ifs(fileName);
	
	if (!ifs.is_open())
		return -1;
	int sum = 0;
	while (!ifs.eof())
	{
		char line[1024];
		ifs.getline(line, 1024);
		sum += getMaxNumberFromString(line);
	}
	ifs.close();
	return sum;
}


int main()
{
	std::cout << sumMaxNumbersFromEachRow("numbers.txt");
}
