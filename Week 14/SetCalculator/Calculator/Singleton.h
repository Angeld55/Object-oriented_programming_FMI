#pragma once
#include "SetExpression.h"

class Singleton : public SetExpression
{
private:
	char name;

public:
	Singleton(char name) : name(name)
	{}

	bool isElementIn(const Element& el) const override;
	SetExpression* clone() const override;
};
