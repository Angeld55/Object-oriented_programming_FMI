#include <iostream>
#include <fstream>
#include "NVector.h"
using namespace std;

int main()
{
	NVector v(3);
	v[2] = 10;
	NVector v2 =  3 * v;
	cout << v2;
	
}
