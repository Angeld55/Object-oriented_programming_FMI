#include <iostream>
using namespace std;

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"


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

		/// <summary>
		/// 
		// FACTORY
		arr[0] = new Rectangle(3, 4, 6, 8);
		arr[1] = new Circle(3, 3, 4);
		arr[2] = new Circle(1, 4, 5);
		arr[3] = new Triangle(1, 1, 2, 2, 3, 3);
		/// <summary>
		/// //
		/// 
		/// </summary>
		/// <returns></returns>
		/// 
		/// 
		/// 
		/// 
		printAreas(arr, 4);
		std::cout << endl;
		printPers(arr, 4);
		std::cout << endl;

		checkPointIn(arr, 4, 3, 3);
		

		freeCollection(arr, 4);
	
}
