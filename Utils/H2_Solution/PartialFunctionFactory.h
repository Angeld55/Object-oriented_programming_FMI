#pragma once
#include "PartialFunction.h"
#include <fstream>

class PartialFunctionFactory
{
public:
	static PartialFunction* create(const char* fileName);
	static PartialFunction* create(std::istream& file);
	static PartialFunction** createArr(std::istream& file, uint16_t size);
};