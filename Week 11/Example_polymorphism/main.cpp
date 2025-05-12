#include <iostream>
using namespace std;
#include "ShapeFactory.h"


void printAreas(const Shape* const * shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
		cout << shapes[i]->getArea() <<endl;
}
void printPers(const Shape* const * shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
		cout << shapes[i]->getPer() << endl;
}

void checkPointIn(const Shape* const* shapes, size_t shapesCount, int x, int y)
{
	for (int i = 0; i < shapesCount; i++)
		cout << shapes[i]->isPointIn(x,y) << endl;
}

void freeCollection(Shape** shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
			delete shapes[i];
		delete[] shapes;
}

int main()
{
		Shape** arr = new Shape*[4];

		for (int i = 0; i < 4; i++)
			arr[i] = shapeFactory();
		
		printAreas(arr, 4);
		std::cout << endl;
		printPers(arr, 4);
		std::cout << endl;
		checkPointIn(arr, 4, 3, 3);

		freeCollection(arr, 4);
}
