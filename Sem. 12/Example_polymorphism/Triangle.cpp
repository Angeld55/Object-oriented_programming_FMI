#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}
double Triangle::getArea() const
{
	Shape::point p1 = getPointAtIndex(0);
	Shape::point p2 = getPointAtIndex(1);
	Shape::point p3 = getPointAtIndex(2);

	return abs(p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y * p2.x - p2.y*p3.x - p3.y*p1.x) / 2.00;
}
double Triangle::getPer() const
{
	Shape::point p1 = getPointAtIndex(0);
	Shape::point p2 = getPointAtIndex(1);
	Shape::point p3 = getPointAtIndex(2);

	return p1.getDist(p2) + p2.getDist(p3) + p3.getDist(p1);
}