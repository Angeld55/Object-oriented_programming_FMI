#pragma once

#include <vector>
#include "../Values/ValueBase/Value.h"

class ValueArray
{
	std::vector<Value*> arr;

	void copyFrom(const ValueArray& other);
	void free();

public:
	void print() const;

	ValueArray() = default;
	ValueArray(const ValueArray& other);
	ValueArray& operator=(const ValueArray& other);

	//factory pattern ? 
	void addDate(const std::string& name, unsigned day, unsigned month, unsigned year);
	void addTime(const std::string& name, unsigned hours, unsigned mins);
	void addString(const std::string& name, const std::string& value);
	void addDateTime(const std::string& name, unsigned day, unsigned month, unsigned year, unsigned hours, unsigned mins);
	~ValueArray();
};