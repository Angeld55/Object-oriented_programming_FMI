#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
	int arr[100000];
public:
	Rectangle(int x1, int y1, int x3, int y3);
	double getArea() const override;
	double getPer() const override;
};