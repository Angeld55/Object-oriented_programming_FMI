#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	if (x1 > x3) 
		std::swap(x1, x3);
	if (y1 < y3)
		std::swap(y1, y3);
	
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
double Rectangle::getPer() const
{
	const Shape::point& p0 = getPointAtIndex(0);
	const Shape::point& p1 = getPointAtIndex(1);
	const Shape::point& p3 = getPointAtIndex(3);

	return 2*(p0.getDist(p1) + p0.getDist(p3));
}

bool Rectangle::isPointIn(int x, int y) const
{
	Shape::point p(x, y);
	return p.x >= getPointAtIndex(0).x && p.x <= getPointAtIndex(2).x &&
		p.y <= getPointAtIndex(0).y && p.y >= getPointAtIndex(2).y;
}
Shape* Rectangle::clone() const
{
	Shape* copy = new Rectangle(*this);
	return copy;
}
