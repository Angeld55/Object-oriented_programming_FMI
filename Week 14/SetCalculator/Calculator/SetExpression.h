#pragma once
#include <cassert>

class SetExpression
{
public:
	struct Element
	{
		bool sets[26] = { false };

		void set(char ch, bool isIn)
		{
			assert(ch >= 'A' && ch <= 'Z');
			sets[ch - 'A'] = isIn;
		}
		bool get(char ch) const
		{
			assert(ch >= 'A' && ch <= 'Z');
			return sets[ch - 'A'];
		}
	};

	virtual bool isElementIn(const Element& el) const = 0;
	virtual SetExpression* clone() const = 0;

	virtual ~SetExpression() = default;
};