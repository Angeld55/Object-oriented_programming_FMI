#pragma once
#include"DynamicCollection.h"

class NormalCollection : public DynamicCollection
{
public:
	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;
};

