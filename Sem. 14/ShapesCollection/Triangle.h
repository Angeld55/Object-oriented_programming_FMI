#pragma once

#include "Shape.h"

class Triangle : public Shape
{

public:
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	double  getArea() const override;
	double getPer() const override;

	Shape* clone() const override;
};