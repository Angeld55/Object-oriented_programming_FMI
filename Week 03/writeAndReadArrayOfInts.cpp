#include <iostream>
#include <fstream>

int main()
{

	{
		const int size = 5;
		int arr[size] = {1, 2, 3, 4, 5};

		std::ofstream ifs("array.dat", std::ios::binary);
		ifs.write((const char*)arr, size * sizeof(int));
	}
	{
		const int size = 5;
		int arr[size] = {};

		std::ifstream ifs("array.dat", std::ios::binary);
		ifs.read((char*)arr, size * sizeof(int));

		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
	}
}
