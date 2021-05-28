#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius;

public:
	Circle(double x, double y, double radius);

	double getArea() const override;
	double getPer() const override; 

	Shape* clone() const override;
};