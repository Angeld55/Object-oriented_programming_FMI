#pragma once
#include"Collection.h"
#include<cstddef> // size_t

class DynamicCollection : public Collection
{
protected:
	int* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void copyFrom(const DynamicCollection& other);
	void moveFrom(DynamicCollection&&);

	void resize(size_t);
public:
	DynamicCollection();

	DynamicCollection(const DynamicCollection& other);
	DynamicCollection(DynamicCollection&& other);

	DynamicCollection& operator=(const DynamicCollection& other);
	DynamicCollection& operator=(DynamicCollection&& other);
	
	~DynamicCollection();
};

