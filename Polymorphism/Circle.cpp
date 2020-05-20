#include "Circle.h"

Circle::Circle(int x, int y, int r) : Shape(1), radius(r)
{
	setPoint(x, y, 0);
}
double Circle::getArea()
{
	return PI * radius * radius;
}
double Circle::getPer()
{
	return 2 * PI * radius;
}
Shape* Circle::clone()
{
	Circle* newCircle = new Circle(*this);
	return newCircle;
}