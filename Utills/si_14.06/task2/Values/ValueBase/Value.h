#pragma once
#include <string>

class Value
{
protected:
	std::string valueName;
public:
	Value(const std::string& valueName);

	std::string getPrefix() const;

	virtual std::string toString() const = 0;

	virtual Value* clone() const = 0;

	virtual ~Value(){}
};