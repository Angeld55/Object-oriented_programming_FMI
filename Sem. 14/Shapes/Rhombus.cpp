#include "Rhombus.h"

Rhombus::Rhombus(double x1, double y1, double x2, double y2) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	double sideLength = getPointAtIndex(0).getDist(getPointAtIndex(1));

	setPoint(2, x2 + sideLength, y2);
	setPoint(3, x1 + sideLength, y1);
}

double Rhombus::getArea() const
{
	return 0.5 *  getPointAtIndex(0).getDist(getPointAtIndex(2)) * getPointAtIndex(1).getDist(getPointAtIndex(3));
}
double Rhombus::getPer() const
{
	return 4 * getPointAtIndex(0).getDist(getPointAtIndex(1));
}
Shape* Rhombus::clone() const
{
	Rhombus* copy = new Rhombus(*this);
	return copy;
}