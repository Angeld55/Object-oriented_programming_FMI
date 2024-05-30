#include "Sorts.h"

struct A
{
	bool operator<(const A& other) const
	{
		return false;
	}
};

int main()
{
	A* str = nullptr;

	BubbleSort(str, 3);
}