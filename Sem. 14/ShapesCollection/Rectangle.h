#pragma once
#include "Shape.h"

class Rectangle : virtual public Shape
{

public:
	Rectangle(double x1, double y1, double x3, double y3);
	double getArea() const override;
	double getPer() const override;

	Shape* clone() const override;
};