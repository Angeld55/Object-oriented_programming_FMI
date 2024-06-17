#include "MinimumPartialFunction.h"
#include <utility>

MinimumPartialFunction::MinimumPartialFunction(PartialFunction**&& functions, uint16_t size) : PartialFunctionOperation(std::move(functions), size)
{
}

int32_t MinimumPartialFunction::operator()(int32_t value) const
{
	
	int32_t min = (*(functions[0]))(value);
	int32_t currVal;
	for (uint16_t i = 1; i < size; i++)
	{
		currVal = (*(functions[i]))(value);
		if (currVal < min)
		{
			min = currVal;
		}
	}

	return min;
}

PartialFunction* MinimumPartialFunction::clone() const
{
    return new MinimumPartialFunction(*this);
}
