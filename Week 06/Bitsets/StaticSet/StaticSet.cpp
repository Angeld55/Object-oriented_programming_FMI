#include "StaticSet.h"

unsigned StaticSet::getBucketIndex(unsigned n) const
{
	return n / BUCKET_SIZE;
}
unsigned StaticSet::getBitIndex(unsigned n) const
{
	return n % BUCKET_SIZE;
}

void StaticSet::add(unsigned n)
{
	if (n > MAX_NUM)
		return;

	unsigned bucketIndex = getBucketIndex(n);
	unsigned bitIndex = getBitIndex(n);

	uint8_t mask = 1 << bitIndex;

	buckets[bucketIndex] |= mask;

}

void StaticSet::remove(unsigned n)
{
	unsigned bucketIndex = getBucketIndex(n);
	unsigned bitIndex = getBitIndex(n);

	uint8_t mask = 1 << bitIndex;
	mask = ~mask;

	buckets[bucketIndex] &= mask;
}

bool StaticSet::contains(unsigned n) const
{
	unsigned bucketIndex = getBucketIndex(n);
	unsigned bitIndex = getBitIndex(n);

	uint8_t mask = 1 << bitIndex;

	return (buckets[bucketIndex] & mask) != 0;
}
void StaticSet::print() const
{
	std::cout << "{ ";
	for (unsigned i = 0; i <= MAX_NUM; i++)
	{
		if (contains(i))
			std::cout << i << " ";
	}
	std::cout << "} " << std::endl;

}

StaticSet UnionOfSets(const StaticSet& lhs, const StaticSet& rhs)
{
	StaticSet result;
	for (int i = 0; i < BUCKETS_COUNT; i++)
		result.buckets[i] = (lhs.buckets[i] | rhs.buckets[i]);
	return result;

}
StaticSet IntersectionOfSets(const StaticSet& lhs, const StaticSet& rhs)
{
	StaticSet result;
	for (int i = 0; i < BUCKETS_COUNT; i++)
		result.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	return result;
}