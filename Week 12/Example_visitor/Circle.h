#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


class Circle : public Shape
{
	double radius;

public:
	Circle(int x, int y, double radius);

	bool intersectsWith(const Shape* other) const override;

	bool intersectsWithTriangle(const Triangle* other) const override;
	bool intersectsWithRect(const Rectangle* other) const override;
	bool intersectsWithCircle(const Circle* other) const override;

};