#include <iostream>
#include "ShapeCollection.h"
using namespace std;

//we don't include the diffrent shapes. 
int main()
{
	ShapeCollection s;

	s.addCircle(3, 4, 1);
	s.addTriangle(1, 2, 9, 4, 0, 0);
	s.addRectangle(1, 1, 9, 9);

	std::cout << s.getIfPointInShapeByIndex(0, 3, 4.5)<< std::endl;
	std::cout << s.getAreaOfFigureByIndex(2) << std::endl;

	
	
}
