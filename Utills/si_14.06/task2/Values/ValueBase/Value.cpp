#include "Value.h"

Value::Value(const std::string& valueName) : valueName(valueName)
{

}

std::string Value::getPrefix() const
{
	return "{ " + valueName + " : ";
}