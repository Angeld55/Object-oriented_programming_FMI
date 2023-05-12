#pragma once
#include"Collection.h"

class CollectionOperation : public Collection
{
protected:
	Collection& left;
	Collection& right;
public:
	CollectionOperation(Collection& l, Collection& r);
};

