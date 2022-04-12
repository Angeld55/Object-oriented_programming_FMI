#include <iostream>
#include <fstream>
#include "Nvector.h"

using namespace std;



int main()
{
	Nvector v(3);
	v[2] = 10;
	Nvector v2 =  3 * v;
	cout << v2;
	
}
