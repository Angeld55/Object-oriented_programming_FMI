#pragma once
#include "Collection.cpp"
#include "PureNumbersCollection.h"

enum CollectionType {
	NORMAL_COLLECTION,
	SORTED_COLLECTION
};

class Set : public Collection
{
	PureNumbersCollection* collection;

public:
	Set(CollectionType);

	Set(const Set&) = delete;
	Set& operator=(const Set&) = delete;

	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;

	~Set();
};
