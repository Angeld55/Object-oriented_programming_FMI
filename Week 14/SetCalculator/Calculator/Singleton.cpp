#include "Singleton.h"

bool Singleton::isElementIn(const Element& el) const
{
	return el.get(name);
}
SetExpression* Singleton::clone() const
{
	return new Singleton(*this);
}