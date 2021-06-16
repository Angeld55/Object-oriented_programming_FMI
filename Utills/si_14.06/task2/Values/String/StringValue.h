#pragma once

#include "../ValueBase/Value.h"

class StringValue : public Value
{
	std::string value;
public:

	StringValue(const std::string& name, const std::string& value);
	
	Value* clone() const;

	std::string toString() const;
};