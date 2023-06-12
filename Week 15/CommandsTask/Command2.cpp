#include "Command2.h"

Command2::Command2(char* str, int N) : str(str), N(N)
{}
void Command2::execute(std::ostream& ofs)
{
	for (int i = 0; i < N; i++)
		ofs << str;
	ofs << std::endl;
}

Command2::~Command2()
{
	delete[] str;
}