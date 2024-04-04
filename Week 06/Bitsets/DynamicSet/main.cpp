#include <iostream>
#include "DynamicSet.h"

int main()
{

	DynamicSet s1(1024);

	s1.add(1);
	s1.add(10);
	s1.add(5);
	s1.print();

	DynamicSet s2(1024);

	s2.add(1);

	s2.add(17);
	s1.add(130);
	s1.print();
	

	DynamicSet intersect = UnionOfSets(s1, s2);
	DynamicSet uni = IntersectionOfSets(s1, s2);

	intersect.print();
	uni.print();

}
