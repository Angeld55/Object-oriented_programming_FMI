#include <iostream>
#include <fstream>

int main()
{
	std::ofstream ofs("myfile.dat", std::ios::out | std::ios::binary);

	int a = 555;
	ofs.write((const char*)&a, sizeof(a));
	ofs.close();
}
