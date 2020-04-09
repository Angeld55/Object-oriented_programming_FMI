#include <iostream>
#include "TestClass.h"

using namespace std;


int main()
{
	TestClass obj1(3, 3, "abc");

	TestClass obj2(obj1);//copy const;

	TestClass obj3(3, 1, "333");

	obj3 = obj1; // operator=;

	TestClass obj4 = obj3; ////copy const;


} //destructors