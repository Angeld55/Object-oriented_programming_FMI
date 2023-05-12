#include "Union.h"

Union::Union(Collection& l, Collection& r) :
	CollectionOperation(l, r) {}

void Union::add(int elem)
{
	this->left.add(elem);
}

void Union::remove(int elem)
{
	if (left.contains(elem))
	{
		left.remove(elem);
	}
	else
	{
		right.remove(elem);
	}
}

unsigned Union::count(int elem) const
{
	return left.count(elem) + right.count(elem);
}

bool Union::contains(int elem) const
{
	return left.contains(elem) || right.contains(elem);
}
