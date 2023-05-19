#include <iostream>
#include "SharedPtr.hpp"

int main()
{
	SharedPtr<int> pt(new int(3));

	SharedPtr<int> p2 = pt;
}