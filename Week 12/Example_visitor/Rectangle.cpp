#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);
}

bool Rectangle::intersectsWith(const Shape* other) const
{
	return other->intersectsWithRect(this);
}

bool Rectangle::intersectsWithTriangle(const Triangle* other) const
{
	std::cout << "Formula for rect with triangle" << std::endl;
	return true;
}
bool Rectangle::intersectsWithRect(const Rectangle* other) const
{
	std::cout << "Formula for rect with rect" << std::endl;
	return true;
}
bool Rectangle::intersectsWithCircle(const Circle* other) const
{
	std::cout << "Formula for rect with circle" << std::endl;
	return true;
}