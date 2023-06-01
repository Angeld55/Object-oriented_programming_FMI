#pragma once
#include "SetExpression.h"

class Singleton : public SetExpression
{
private:
	char name;

public:
	Singleton(char name) : name(name)
	{}

	virtual bool isElementIn(const Element& el) const override;
	virtual SetExpression* clone() const override;
};