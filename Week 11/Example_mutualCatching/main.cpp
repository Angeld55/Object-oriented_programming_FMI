#include <iostream>
using namespace std;

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"



bool intersect(const Shape* sh1, const Shape* sh2)
{
	return sh1->intersectsWith(sh2);
}
int main()
{
		Shape** arr = new Shape*[4];

		arr[0] = new Rectangle(3, 4, 6, 8);
		arr[1] = new Circle(3, 3, 4);
		arr[2] = new Circle(1, 4, 5);
		arr[3] = new Triangle(1, 1, 2, 2, 3, 3);

		intersect(arr[0], arr[1]);
		intersect(arr[1], arr[2]);
		intersect(arr[2], arr[3]);


		for (int i = 0; i < 4; i++)
			delete arr[i];
	
		delete[] arr;
	
}
