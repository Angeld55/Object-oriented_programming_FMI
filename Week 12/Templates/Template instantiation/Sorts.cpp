#include "Sorts.h"
#include <algorithm>

struct A;
template <class T>
void SelectionSort(T* pArr, size_t Size)
{
	if (!pArr || Size == 0)
		return;

	for (size_t i = 0; i < Size - 1; i++)
	{
		size_t min = i;

		for (size_t j = i + 1; j < Size; j++)
		{
			if (pArr[j] < pArr[min])
				min = j;
		}

		if (pArr[min] < pArr[i])
			std::swap(pArr[i], pArr[min]);
	}
}

template <class T>
void BubbleSort(T* pArr, size_t Size)
{
	if (!pArr || Size == 0)
		return;

	for (size_t i = 0; i < Size - 1; i++)
	{
		for (size_t j = Size - 1; j > i; j--)
		{
			if (pArr[j] < pArr[j - 1])
				std::swap(pArr[j], pArr[j - 1]);
		}
	}
}

template void SelectionSort<double>(double* pArr, size_t Size);
template void BubbleSort<double>(double* pArr, size_t Size);


template void BubbleSort<A>(A* pArr, size_t Size);