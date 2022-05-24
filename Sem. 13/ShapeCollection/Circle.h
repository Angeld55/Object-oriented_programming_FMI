#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius;

public:
	Circle(int x, int y, double radius);

	double getArea() const override;
	double getPer() const override; 
	bool isPointIn(int x, int y) const override;
	Shape* clone() const override;
};