#include "Calculator/SetCalculator.h"
#include <iostream>

int main()
{
	SetCalculator s("(((A^B)vC)vX)");

	SetExpression::Element el;
	el.set('A', true);
	el.set('B', true);
	el.set('C', true);

	std::cout << s.isElementIn(el);
}