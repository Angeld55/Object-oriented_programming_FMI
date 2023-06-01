#include "Operation.h"

UnaryOperation::UnaryOperation(char op, SetExpression* sub) : op(op), sub(sub)
{}

bool UnaryOperation::isElementIn(const Element& el) const
{
	switch (op)
	{
	case '!': return !sub->isElementIn(el);
	}
	return false;
}
SetExpression* UnaryOperation::clone() const
{
	return new UnaryOperation(op, sub->clone());
}

UnaryOperation::~UnaryOperation()
{
	delete sub;
}


BinaryOperation::BinaryOperation(char op, SetExpression* left, SetExpression* right) : op(op), left(left), right(right)
{}

bool BinaryOperation::isElementIn(const Element& el) const
{
	switch (op)
	{
	case 'v': return left->isElementIn(el) || right->isElementIn(el);
	case '^': return left->isElementIn(el) && right->isElementIn(el);
	case '\\': return left->isElementIn(el) && !right->isElementIn(el);
	case 'x': return (left->isElementIn(el) && !right->isElementIn(el)) || (!left->isElementIn(el) && right->isElementIn(el));
	}
	return false;
}
SetExpression* BinaryOperation::clone() const
{
	return new BinaryOperation(op, left->clone(), right->clone());
}

BinaryOperation::~BinaryOperation()
{
	delete left, right;
}