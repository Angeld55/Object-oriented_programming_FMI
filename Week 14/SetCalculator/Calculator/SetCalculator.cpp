#include "SetCalculator.h"

SetCalculator::SetCalculator(const MyString& str)
{
	ptr = parse(str);
}

bool SetCalculator::isElementIn(const SetExpression::Element& el) const
{
	return ptr->isElementIn(el);
}

SetExpression* SetCalculator::parse(const StringView& str)
{
	if (str.length() == 1)
		return new Singleton(str[0]);

	// should be an operation
	StringView withoutBrackets = str.substr(1, str.length() - 2);

	int count = 0;
	for (size_t i = 0; i < withoutBrackets.length(); i++)
	{
		if (withoutBrackets[i] == '(')
			count++;
		else if (withoutBrackets[i] == ')')
			count--;
		else if (count == 0 && isOperation(withoutBrackets[i]))
		{
			if (withoutBrackets[i] == '!')
				return new UnaryOperation('!', parse(withoutBrackets.substr(1, str.length() - 1)));
			else
				return new BinaryOperation(withoutBrackets[i], parse(withoutBrackets.substr(0, i)), parse(withoutBrackets.substr(i + 1, withoutBrackets.length() - i -1)));
		}
	}
}
bool SetCalculator::isOperation(char ch) const
{
	return ch == 'v' || ch == '^' || ch == '\\' || ch == 'x' || ch == '!';
}

SetCalculator::SetCalculator(const SetCalculator& other)
{
	copyFrom(other);
}
SetCalculator& SetCalculator::operator=(const SetCalculator& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
SetCalculator::~SetCalculator()
{
	free();
}

void SetCalculator::SetCalculator::copyFrom(const SetCalculator& other)
{
	ptr = other.ptr->clone();
}
void SetCalculator::SetCalculator::free()
{
	delete ptr;
}