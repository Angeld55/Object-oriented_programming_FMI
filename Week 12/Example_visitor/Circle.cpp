#include "Circle.h"

const double PI = 3.1415;
Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius)
{
	setPoint(0, x, y);
}

bool Circle::intersectsWith(const Shape* other) const
{
	return other->intersectsWithCircle(this);
}

bool Circle::intersectsWithTriangle(const Triangle* other) const
{
	std::cout << "Formula for circle with triangle" << std::endl;
	return true;
}
bool Circle::intersectsWithRect(const Rectangle* other) const
{
	std::cout << "Formula for circle with rect" << std::endl;
	return true;
}
bool Circle::intersectsWithCircle(const Circle* other) const
{
	std::cout << "Formula for circle with circle" << std::endl;
	return true;
}
