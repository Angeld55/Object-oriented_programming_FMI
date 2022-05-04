#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;


struct Test
{
	bool b;
	int x;
};

int main()
{

	{ //write
		Test t = { true, 45 };
		ofstream file("testObj.bat", ios::binary);
		
		if (!file.open())
			return -1;

		file.write((const char*)&t, sizeof(t));
	}

	{ //read
		Test t;
		ifstream file("testObj.bat", ios::binary);
		
		if (!file.open())
			return -1;

		file.read((char*)&t, sizeof(t));
		std::cout << t.b << " " << t.x << std::endl;
	}

}
