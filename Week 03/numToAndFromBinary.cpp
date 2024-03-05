#include <iostream>
#include <fstream>

int main()
{

	{
		int x = 12345;
		std::ofstream ofs("num.dat", std::ios::out | std::ios::binary);
		ofs.write((const char*)&x, sizeof(x));
	}
	{
		int n;
		std::ifstream ifs("num.dat", std::ios::in | std::ios::binary);
		ifs.read((char*)&n, sizeof(n));
		std::cout << n << std::endl;
	}

}
