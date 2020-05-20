#include "Shape.h"

Shape::Shape(int pointsCount)
{
	points = new Point[pointsCount];
	this->pointsCount = pointsCount;
}

void Shape::setPoint(int x, int y, int ind)
{
	Point current(x, y);
	points[ind] = current;
		
}

const Point& Shape::getPoint(int ind)
{
	return points[ind];
}

void Shape::CopyFrom(const Shape& other)
{
	points = new Point[other.pointsCount];
	pointsCount = other.pointsCount;

	for (int i = 0; i < pointsCount; i++)
		points[i] = other.points[i];
}
void Shape::Free()
{
	delete[] points;
	pointsCount = 0;
}
Shape::Shape(const Shape& other)
{
	CopyFrom(other);
}
Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Shape::~Shape()
{
	Free();
}
