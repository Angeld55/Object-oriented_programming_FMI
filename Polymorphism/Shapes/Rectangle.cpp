#include "Rectangle.h"


Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(x1, y1, 0);
	setPoint(x3, y3, 2);
	setPoint(x1, y3, 1);
	setPoint(x3, y1, 3);
}

double Rectangle::getPer()
{
	return 2 * (getPoint(0).getDist(getPoint(1)) + getPoint(1).getDist(getPoint(2)) );
}
double Rectangle::getArea()
{
	return getPoint(0).getDist(getPoint(1)) * getPoint(1).getDist(getPoint(2));
}
Shape* Rectangle::clone()
{
	Rectangle* newRect = new Rectangle(*this);
	return newRect;
}