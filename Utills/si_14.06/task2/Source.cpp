#include  <iostream>
#include "ValueArray/ValueArray.h"

int main()
{
	ValueArray v;

	v.addDate("First school day",15, 9, 2021);
	v.addTime("Work day start", 10, 15);
	v.addDateTime("Portugal - Germany", 19, 06, 2021, 19, 10);
	v.addString("Name", "Test");

	v.print();
}