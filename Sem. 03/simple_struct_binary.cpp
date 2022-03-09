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

		file.write((char*)&t, sizeof(t)); //since the data is grouped in the struct, we can save it like this.
	}

	{ //read
		Test t;
		ifstream file("testObj.bat", ios::binary);

		file.read((char*)&t, sizeof(t));
		std::cout << t.b << " " << t.x << std::endl;
	}

}
