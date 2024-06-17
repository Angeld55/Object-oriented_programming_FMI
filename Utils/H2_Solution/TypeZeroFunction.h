#pragma once
#include "MyVector.h"
#include "Pair.h"
#include <cstdint>
#include <fstream>

class TypeZeroFunction
{
private:
	MyVector args;
	MyVector res;
	int16_t size = 0;
public:
	TypeZeroFunction(uint16_t size, std::istream& file);

	Pair operator()(int32_t value) const;

};
