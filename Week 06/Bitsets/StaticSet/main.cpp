#pragma once
#include <iostream>
#include "StaticSet.h"

int main()
{

	StaticSet s1;

	s1.add(1);
	s1.add(10);
	s1.add(5);
	s1.print();

	StaticSet s2;

	s2.add(1);

	s2.add(17);
	s1.add(130);
	s1.print();
	

	StaticSet intersect = UnionOfSets(s1, s2);
	StaticSet uni = IntersectionOfSets(s1, s2);

	intersect.print();
	uni.print();

}