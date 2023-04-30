#include "UniquePointerOfA.h"
#include <iostream>

void print(UniquePointerOfA ptr)
{
	std::cout << (*ptr).a << " " << (*ptr).b << std::endl;
}
int main()
{
	UniquePointerOfA ptr(new A());

	UniquePointerOfA other(std::move(ptr));


	print(std::move(other));
}