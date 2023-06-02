#pragma once
#include "SetExpression.h"

class UnaryOperation : public SetExpression
{
private:
	char op;
	SetExpression* sub;

public:
	UnaryOperation(char op, SetExpression* sub);

	bool isElementIn(const Element& el) const override;
	SetExpression* clone() const override;

	~UnaryOperation();
};


class BinaryOperation : public SetExpression
{
private:
	char op;
	SetExpression* left;
	SetExpression* right;

public:
	BinaryOperation(char op, SetExpression* left, SetExpression* right);

	bool isElementIn(const Element& el) const override;
	SetExpression* clone() const override;

	~BinaryOperation();
};
