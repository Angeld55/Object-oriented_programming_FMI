#pragma once
#include "Shape.h"

class Rhombus : virtual public Shape
{
public:
	Rhombus(double x1, double y1, double x2, double y2);

	double  getArea() const override;
	double getPer() const override;
	Shape* clone() const override;
};