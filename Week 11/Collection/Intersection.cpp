#include "Intersection.h"

Intersection::Intersection(Collection& left, Collection& right) :
	CollectionOperation(left, right) {}

// Добавяме към по - малкия
// Ако са равен брой добавяме и към двете
void Intersection::add(int elem)
{
	int lCount = left.count(elem);
	int rCount = right.count(elem);

	if (lCount > rCount)
	{
		right.add(elem);
	}
	else
	{
		left.add(elem);

		if (lCount == rCount)
		{
			right.add(elem);
		}
	}

}

// Аналогично с добавянето
void Intersection::remove(int elem)
{
	int lCount = left.count(elem);
	int rCount = right.count(elem);

	if (lCount > rCount)
	{
		right.remove(elem);
	}
	else
	{
		left.remove(elem);

		if (lCount == rCount)
		{
			right.remove(elem);
		}
	}
}

unsigned Intersection::count(int elem) const
{
	int lCount = left.count(elem);
	int rCount = right.count(elem);
	return lCount < rCount ? lCount : rCount;
}

bool Intersection::contains(int elem) const
{
	return left.contains(elem) && right.contains(elem);
}
