#pragma once
#include <iostream>
struct Point
{
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point() : Point(0,0)
	{}
	double getDist(const Point& other) const
	{
		return sqrt((x - other.x)*(x - other.x) + (y - other.y) * (y - other.y));
	}
};