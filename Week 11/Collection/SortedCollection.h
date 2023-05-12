#pragma once
#include"DynamicCollection.h"
class SortedCollection : public DynamicCollection
{
	// Взема най - лявото срещане на подадения елемент
	int lowerBound(int) const;

	// Взема най - дясното срещане на подадения елемент
	int upperBound(int) const;
public:
	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;

	~SortedCollection() = default;
};

