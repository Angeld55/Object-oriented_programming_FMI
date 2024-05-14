#pragma once
#include"DynamicCollection.h"

class IntervalCollection : public DynamicCollection
{
private:
	int start;
	int end;
public:
	IntervalCollection(int start, int end);
	unsigned intervalLength() const;

	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;
};