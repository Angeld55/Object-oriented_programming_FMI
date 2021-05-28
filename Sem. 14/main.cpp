#include <iostream>
#include "Collection/ShapesCollection.h"
using namespace std;


//Ромб
int main()
{
	ShapesCollection s;

	s.addCircle(3, 4, 5);
	s.addTriangle(2, 3, 54, 3, 2, 1);
	s.addRectangle(1, 2, 3, 4);
	s.addRhombus(3, 2, 0, 0);
	s.addSquare(4, 4, 10);

	s.printAreas();
}
