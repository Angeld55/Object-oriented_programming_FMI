#pragma once
#include"CollectionOperation.h"
class Intersection : public CollectionOperation
{
public:
	Intersection(Collection& left, Collection& right);

	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;
};

