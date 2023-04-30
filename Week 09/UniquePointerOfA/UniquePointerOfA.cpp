#include "UniquePointerOfA.h"

UniquePointerOfA::UniquePointerOfA(A* ptr) : ptr(ptr)
{}


UniquePointerOfA::UniquePointerOfA(UniquePointerOfA&& other) noexcept
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

UniquePointerOfA& UniquePointerOfA::operator=(UniquePointerOfA&& other) noexcept
{
	if (this != &other)
	{
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

A& UniquePointerOfA::operator*()
{
	return *ptr;
}
const A& UniquePointerOfA::operator*() const
{
	return *ptr;
}

UniquePointerOfA::~UniquePointerOfA()
{
	delete ptr;
}