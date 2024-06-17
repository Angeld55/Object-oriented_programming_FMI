#pragma once
#include "PartialFunction.h"

class PartialFunctionOperation : public PartialFunction
{
private:
	void free();
	void copyFrom(const PartialFunctionOperation& other);
	void moveFrom(PartialFunctionOperation&& other);
protected:
	PartialFunction** functions = nullptr;
	uint16_t size = 0;
public:
	PartialFunctionOperation(PartialFunction**&& functions, uint16_t size);
	PartialFunctionOperation(const PartialFunctionOperation& other);
	PartialFunctionOperation(PartialFunctionOperation&& other) noexcept;
	PartialFunctionOperation& operator=(const PartialFunctionOperation& other);
	PartialFunctionOperation& operator=(PartialFunctionOperation&& other) noexcept;
	~PartialFunctionOperation() noexcept;

	bool isDefined(int32_t val) const override;
};
