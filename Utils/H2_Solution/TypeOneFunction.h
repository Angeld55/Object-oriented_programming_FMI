#pragma once
#include "Pair.h"
#include "MyVector.h"
#include <cstdint>
#include <fstream>

class TypeOneFunction
{
private:
	MyVector undefValues;
	int16_t size = 0;
public:
	TypeOneFunction(int16_t size, std::istream& file);

	Pair operator()(int32_t value) const;

};