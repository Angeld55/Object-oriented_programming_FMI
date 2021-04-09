#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
	Person p("Ivan", 13);
	Person p2("Petur", 12);

	p = p2;

	p2.setName("Aleks");
	p.print();
	p2.print();

} 
