#include <stdexcept>
#include "PartialFunctionFactory.h"
#include "PartialFunctionByCriteria.hpp"
#include "MaximumPartialFunction.h"
#include "MinimumPartialFunction.h"
#include "TypeZeroFunction.h"
#include "TypeOneFunction.h"
#include "TypeTwoFunction.h"

namespace Constraints
{
	constexpr int16_t MAX_VALUE = 32;
}

static unsigned getWordLength(std::istream& file)
{
	unsigned currPos = file.tellg();
	unsigned length = 0;

	while (file.get())
	{
		length++;
	}

	file.seekg(currPos);
	return length;
}

PartialFunction* PartialFunctionFactory::create(const char* fileName)
{
	if (!fileName || fileName[0] == '\0')
	{
		throw std::invalid_argument("File name is not correct.");
	}

	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		throw std::invalid_argument("File is not open.");
	}

	return create(file);
}

PartialFunction* PartialFunctionFactory::create(std::istream& file)
{
	uint16_t n, t;

	file.read((char*)&n, sizeof(n));
	if (n > Constraints::MAX_VALUE )
	{
		throw std::invalid_argument("Value is not correct.");
	}

	file.read((char*)&t, sizeof(t));
	if (t == 0)
	{
		TypeZeroFunction func(n, file);
		return new PartialFunctionByCriteria<TypeZeroFunction>(func);
	}
	else if (t == 1)
	{
		TypeOneFunction func1(n, file);
		return new PartialFunctionByCriteria<TypeOneFunction>(func1);
	}
	else if (t == 2)
	{
		TypeTwoFunction func2(n, file);
		return new PartialFunctionByCriteria<TypeTwoFunction>(func2);
	}
	else if (t == 3)
	{
		PartialFunction** arr = createArr(file, n);
		PartialFunction* temp = new MaximumPartialFunction(std::move(arr), n);
		delete[] arr;
		return temp;
	}
	else if (t == 4)
	{
		PartialFunction** arr = createArr(file, n);
		PartialFunction* temp = new MinimumPartialFunction(std::move(arr), n);
		delete[] arr;
		return temp;
	}
	else
	{
		throw std::invalid_argument("Error.");
	}
}

PartialFunction** PartialFunctionFactory::createArr(std::istream& is, uint16_t size)
{
	PartialFunction** arr = new PartialFunction*[size] {nullptr};
	uint16_t ind = 0;

	while (size--)
	{
		uint16_t wordSize = getWordLength(is);
		char* buff = new char[wordSize + 1];
		is.read(buff, wordSize + 1);
		arr[ind++] = create(buff);
		delete[] buff;
	}

	return arr;
}
