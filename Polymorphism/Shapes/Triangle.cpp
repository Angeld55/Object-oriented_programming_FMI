#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
	setPoint(x1, y1, 0);
	setPoint(x2, y2, 1);
	setPoint(x3, y3, 2);
}

double Triangle::getArea()
{
	double sideA = getPoint(0).getDist(getPoint(1));
	double sideB = getPoint(1).getDist(getPoint(2));
	double sideC = getPoint(2).getDist(getPoint(0));

	double halfPer = getPer() / 2;

	return sqrt(halfPer * (halfPer - sideA) *
		(halfPer - sideB) * (halfPer - sideC));
}
double Triangle::getPer()
{
	return getPoint(0).getDist(getPoint(1)) +
		getPoint(1).getDist(getPoint(2)) +
		getPoint(2).getDist(getPoint(0));
}
Shape* Triangle::clone()
{
	Triangle* newTriangle = new Triangle(*this);
	return newTriangle;
}