#include "MaximumPartialFunction.h"
#include <utility>

MaximumPartialFunction::MaximumPartialFunction(PartialFunction**&& functions, uint16_t size) : PartialFunctionOperation(std::move(functions), size)
{
}

int32_t MaximumPartialFunction::operator()(int32_t value) const
{
	int32_t max = (*(functions[0]))(value);
	int32_t curr;
	for (uint16_t i = 1; i < size; i++)
	{
		curr = (*(functions[i]))(value);
		if (curr > max)
		{
			max = curr;
		}
	}

	return max;
}

PartialFunction* MaximumPartialFunction::clone() const
{
    return new MaximumPartialFunction(*this);
}
