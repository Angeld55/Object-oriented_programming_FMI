#include <iostream>
#include <chrono>

using namespace std;

bool checkIfObratim(size_t element, size_t Z)
{
	for (int i = 1; i < Z; i++)
	{
		if ((i * element) % Z == 0)
		{
			std::cout << "Obratniq element na " << element << " e " << i << std::endl;
			return true;
		}
	}
	return false;
}
size_t countDivisers(size_t Z)
{
	size_t count = 0;
	for (int i = 1; i < Z; i++)
	{
		if (checkIfObratim(i,Z))
			count++;
		else
		{
			std::cout << "Neobratim " << i << std::endl;
		}
	}
	return count;
}
int main()
{

	cout << countDivisers(4096) << endl;

}
