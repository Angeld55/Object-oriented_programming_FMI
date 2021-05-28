#include "Square.h"

Square::Square(double x, double y, double sideLength) : Rectangle(x, y, x + sideLength, y - sideLength), Rhombus(x, y, x, y - sideLength), Shape(4)
{}

double Square::getArea() const
{
	return Rhombus::getArea();
}
double Square::getPer() const
{
	return Rectangle::getPer();
};

Shape* Square::clone() const
{
	Square* copy = new Square(*this);
	return copy;
}