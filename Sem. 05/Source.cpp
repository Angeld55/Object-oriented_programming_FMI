#include <iostream>
#include "Interval.h"

using namespace std;


int main()
{
	Interval i(1, 11);

	cout << i.calcDiffrentDigitNumbersInTheInverval() << endl;

	cout << i.getLength() << endl;
	
}