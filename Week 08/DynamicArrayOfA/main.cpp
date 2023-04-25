#include <iostream>
#include "DynamicArrayOfA.h"

int main()
{
	DynamicArray arraysOfA;

	arraysOfA.pushBack({ 3,4 });

	A obj{ 4,3 };

	arraysOfA.pushBack(obj);
}