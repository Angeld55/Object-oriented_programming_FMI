#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ofs("myfile.dat", std::ios::in | std::ios::binary);

	int a;
	ofs.read((char*)&a, sizeof(a));
	ofs.close();
}
