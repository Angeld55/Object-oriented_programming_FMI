#include "Command1.h"


Command1::Command1(int* arr, int N) : arr(arr), N(N)
{
}

void Command1::execute(std::ostream& ofs)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
		ofs << arr[i] << ' ';
	}
	ofs << sum << std::endl;
}

Command1::~Command1()
{
	delete[] arr;
}
