#include <iostream>
#include "Time.h"

using namespace std;


int main()
{
	Time t(12, 30, 30);

	t.print();
	t.addMinutes(45);
	t.print();
}