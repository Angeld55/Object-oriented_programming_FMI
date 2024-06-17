#pragma once
#include "PartialFunctionOperation.h"

class MinimumPartialFunction : public PartialFunctionOperation
{
public:
	MinimumPartialFunction(PartialFunction**&& functions, uint16_t size);

	int32_t operator()(int32_t value) const override;
	PartialFunction* clone() const override;

};
