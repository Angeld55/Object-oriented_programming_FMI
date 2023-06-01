#pragma once
#include "SetExpression.h"

class UnaryOperation : public SetExpression
{
private:
	char op;
	SetExpression* sub;

public:
	UnaryOperation(char op, SetExpression* sub);

	virtual bool isElementIn(const Element& el) const override;
	virtual SetExpression* clone() const override;

	virtual ~UnaryOperation();
};


class BinaryOperation : public SetExpression
{
private:
	char op;
	SetExpression* left;
	SetExpression* right;

public:
	BinaryOperation(char op, SetExpression* left, SetExpression* right);

	virtual bool isElementIn(const Element& el) const override;
	virtual SetExpression* clone() const override;

	virtual ~BinaryOperation();
};