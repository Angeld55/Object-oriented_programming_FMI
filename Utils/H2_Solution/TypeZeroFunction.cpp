#include "TypeZeroFunction.h"

TypeZeroFunction::TypeZeroFunction(uint16_t n, std::istream& is) : size(n), args(n), res(n)
{
	args.readFromFile(is, n);
	res.readFromFile(is, n);
}


Pair TypeZeroFunction::operator()(int32_t value) const
{
	int ind = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (args[i] == value)
		{
			ind = i;
			break;
		}
	}

	if (ind != -1)
	{
		return Pair{ true, res[ind] };
	}

	return Pair{ false, 0 };
}

