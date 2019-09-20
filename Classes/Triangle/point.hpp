#include <iostream>

struct Point
{
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	double DistTo(const Point& other)
	{
		int dx = x - other.x;
		int dy = y - other.y;
		return sqrt(dx*dx + dy*dy);
	}
	int x;
	int y;
};