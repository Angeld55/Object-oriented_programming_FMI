#include "StringValue.h"

StringValue::StringValue(const std::string& name, const std::string& value) : Value(name), value(value)
{}

std::string StringValue::toString() const
{
	return getPrefix() + '\"' + value + '\"' + "}";
}

Value* StringValue::clone() const
{
	return new StringValue(*this);
}