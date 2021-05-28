#include "Circle.h"

const double PI = 3.1415;
Circle::Circle(double x, double y, double radius) : Shape(1), radius(radius)
{
	setPoint(0, x, y);
}

double Circle::getArea() const
{
	return PI * radius * radius;
}
double Circle::getPer() const
{
	return 2 * PI * radius;
}

Shape* Circle::clone() const
{
	Circle* copy = new Circle(*this);
	return copy;
}