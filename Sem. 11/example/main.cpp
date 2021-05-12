#include<iostream>
#include<iostream>
#include "Person.h"
using namespace std;

Person createPerson(const char* name, int age)
{
	Person p(name, age);

	return p;
}

int main()
{
	Person p2("Petur",18);
	p2 = createPerson("Ivan", 23);
}