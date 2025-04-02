#pragma once
#include <iostream>

class DynamicSet
{
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void freeDynamic();
	void copyDynamic(const DynamicSet& other);

	unsigned getBucketIndex(unsigned num) const;
public:
	DynamicSet() = default;

	//explicit prevents implicit casting
	explicit DynamicSet(unsigned n); // [0....n] (n + 1 числа)

	DynamicSet(const DynamicSet& other);
	DynamicSet& operator=(const DynamicSet& other);
	~DynamicSet();

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num) const;
	void print() const;
	friend DynamicSet UnionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
	friend DynamicSet IntersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);

};

class SetByCriteria : public DynamicSet
{
public:
	SetByCriteria(int n, bool(*cr)(unsigned)) : DynamicSet(n)
	{
		for (int i = 0; i < n; i++)
		{
			if (cr(i))
				add(i);
		}
	}
};