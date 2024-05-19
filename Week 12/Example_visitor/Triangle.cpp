#include "Triangle.h"
#include <limits>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

bool Triangle::intersectsWith(const Shape* other) const
{
	return other->intersectsWithTriangle(this);
}

bool Triangle::intersectsWithTriangle(const Triangle* other) const
{
	std::cout << "Formula for triangle with triangle" << std::endl;
	return true;
}
bool Triangle::intersectsWithRect(const Rectangle* other) const
{
	std::cout << "Formula for triangle with rect" << std::endl;
	return true;
}
bool Triangle::intersectsWithCircle(const Circle* other) const
{
	std::cout << "Formula for triangle with circle" << std::endl;
	return true;
}