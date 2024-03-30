#pragma once
#include <iostream>

constexpr unsigned MAX_NUM = 1023;
constexpr unsigned NUMBERS_COUNT = MAX_NUM + 1;
constexpr unsigned BUCKET_SIZE = sizeof(uint8_t) * 8;
constexpr unsigned BUCKETS_COUNT = NUMBERS_COUNT / BUCKET_SIZE + 1;

class StaticSet
{
	uint8_t buckets[BUCKETS_COUNT] = { 0 };
	unsigned getBucketIndex(unsigned n) const;
	unsigned getBitIndex(unsigned n) const;
public:
	StaticSet() = default;

	void add(unsigned n);
	void remove(unsigned n);

	bool contains(unsigned n) const;
	void print() const;

	friend StaticSet UnionOfSets(const StaticSet& lhs, const StaticSet& rhs);
	friend StaticSet IntersectionOfSets(const StaticSet& lhs, const StaticSet& rhs);

};
