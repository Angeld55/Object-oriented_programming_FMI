#pragma once
#include "Pair.h"
#include "MyVector.h"
#include <cstdint>
#include <fstream>

class TypeTwoFunction
{
private:
	MyVector oneValues;
	int16_t size = 0;
public:
	TypeTwoFunction(int16_t size, std::istream& file);

	Pair operator()(int32_t value) const;
};