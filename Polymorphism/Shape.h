#pragma once

#include "Point.h"

class Shape
{
	Point* points;
	int pointsCount;

	void CopyFrom(const Shape& other);
	void Free();

public:
	Shape(int pointsCount);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	void setPoint(int x, int y, int ind);
	const Point& getPoint(int ind);

	virtual double getPer() =0;
	virtual double getArea() = 0;

	virtual Shape* clone() = 0;

};