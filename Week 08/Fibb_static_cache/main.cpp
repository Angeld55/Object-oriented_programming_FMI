#include <iostream>
#include "MapKeys0toN.h"

unsigned fibb(unsigned n)
{
	if (n == 0 || n == 1)
		return 1;
	static MapKeys0toN cache(0);

	if (cache.contains(n))
	{
		return cache.getValue(n);
	}
	else
	{
		unsigned result = fibb(n - 1) + fibb(n - 2);
		cache.add(n, result);
		return result;
	}
}
int main()
{
	std::cout << fibb(30) << std::endl;
	std::cout << fibb(30);

	return 0;
}
