#include"SortedCollection.h"
#include<iostream>
#include"IntervalCollection.h"
#include"NormalCollection.h"
#include"Union.h"
#include"Intersection.h"


// c1 = [1, 4, 10, 3, 2, 0] - normal
// c2 = [1, 11, 14] - interval[0, 16]
// c3 = [3, 4, 4, 5, 14, 0] - sorted
// 
// c = (c1 u c2) ^ c3 = [0, 3, 4, 14]
int main() 
{
	Collection* c1 = new NormalCollection();
	c1->add(1);
	c1->add(4);
	c1->add(10);
	c1->add(3);
	c1->add(2);
	c1->add(0);


	Collection* c2 = new IntervalCollection(0, 16);
	c2->add(1);
	c2->add(11);
	c2->add(14);
	c2->add(0);

	Collection* c3 = new SortedCollection();
	c3->add(5);
	c3->add(4);
	c3->add(4);
	c3->add(14);
	c3->add(0);
	c3->add(3);

	Collection* leftUnion = new Union(*c1, *c2);
	Collection* intersect = new Intersection(*leftUnion, *c3);

	for (size_t i = 0; i < 16; i++)
	{
		size_t count = intersect->count(i);

		for (size_t j = 0; j < count; j++)
		{
			std::cout << i << " ";
		}
	}
}