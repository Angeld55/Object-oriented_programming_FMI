#include "Rectangle.h"
#include <algorithm>

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);
}
double Rectangle::getArea() const
{
	const Shape::point& p0 = getPointAtIndex(0);
	const Shape::point& p1 = getPointAtIndex(1);
	const Shape::point& p3 = getPointAtIndex(3);

	return p0.getDist(p1) * p0.getDist(p3);

}

bool Rectangle::isPointIn(int x, int y) const
{
	Shape::point p(x, y);
	int leftX = std::min(getPointAtIndex(0).x, getPointAtIndex(2).x);
	int rightX = std::max(getPointAtIndex(0).x, getPointAtIndex(2).x);

	int upY = std::max(getPointAtIndex(0).y, getPointAtIndex(2).y);
	int downY = std::min(getPointAtIndex(0).y, getPointAtIndex(2).y);
	
	return p.x >= leftX && p.x <= rightX &&
		p.y <= upY && p.y >= downY;
}
