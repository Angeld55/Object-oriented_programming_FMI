#pragma once
#include "SetExpression.h"
#include "Singleton.h"
#include "Operation.h"
#include "../MyString/StringView.h"

class SetCalculator
{
private:
	SetExpression* ptr;

	void copyFrom(const SetCalculator& other);
	void free();

	SetExpression* parse(const StringView& str);
	bool isOperation(char ch) const;

public:
	SetCalculator(const SetCalculator& other);
	SetCalculator& operator=(const SetCalculator& other);
	~SetCalculator();

	SetCalculator(const MyString& str);

	bool isElementIn(const SetExpression::Element& el) const;
};