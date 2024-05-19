#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int x1, int y1, int x3, int y3);
	double getArea() const override;
	bool isPointIn(int x, int y) const override;
	Shape* clone() const override;
};