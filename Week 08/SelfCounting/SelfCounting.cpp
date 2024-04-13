#include "SelfCounting.h"

//static class member's should be
//initialized here ( "only in one .cpp" )
unsigned SelfCounting::liveObjectsCount = 0;
unsigned SelfCounting::createdCount = 0;

SelfCounting::SelfCounting() : SelfCounting(42)  //initialization of constants
						//can only be done while creating them
						//so the only possible way is in
						//the initialization list
{
}

SelfCounting::SelfCounting(int val) : const_val(val)
{
	liveObjectsCount++;
	createdCount++;
}
SelfCounting::SelfCounting(const SelfCounting& other) : const_val(other.const_val)
{
	liveObjectsCount++;
	createdCount++;
}

SelfCounting::~SelfCounting()
{
	liveObjectsCount--;
}

unsigned SelfCounting::getLiveObjectsCount()
{
	return liveObjectsCount;
}

unsigned SelfCounting::getCreatedCount()
{
	return createdCount;
}
