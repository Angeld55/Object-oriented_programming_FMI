#pragma once

struct A
{
	bool operator<(const A& other) const
	{
		return false;
	}
};

template <class T> void SelectionSort(T* pArr, size_t Size);
template <class T> void BubbleSort(T* pArr, size_t Size);
