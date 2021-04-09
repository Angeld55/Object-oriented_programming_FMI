#include <iostream>
#include "PersonAdvanced.h"
using namespace std;

int main()
{
	PersonAdvanced p("Ivan", 13);
	PersonAdvanced p2("Petur", 12);

	p = p2;

	p2.setName("Aleks");
	p.print();
	p2.print();

} 
