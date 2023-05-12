#pragma once
#include"CollectionOperation.h"
class Union : public CollectionOperation
{
public:
	Union(Collection& l, Collection& r);
	
	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;
};