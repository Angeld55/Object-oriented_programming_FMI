#pragma once
#include <iostream>


class Triangle;
class Rectangle;
class Circle;

class Shape   // Abstract class - no instances of Shape are allowed!
{
protected:
	struct point
	{
		point() :x(0), y(0){}
		point(int x, int y) :x(x), y(y){}
		int x;
		int y;
		double getDist(const point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx*dx + dy*dy);
		}
	};
	const point& getPointAtIndex(size_t index) const;
private:
	point* points;
	size_t pointsCount;

	void copyFrom(const Shape& other);
	void free();


public:
	Shape(size_t pointsCount);

	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape(); //!!!!!!

	void setPoint(size_t pointIndex, int x, int y);


	virtual bool intersectsWith(const Shape* other) const = 0;

	virtual bool intersectsWithTriangle(const Triangle* other) const = 0;
	virtual bool intersectsWithRect(const Rectangle* other) const = 0;
	virtual bool intersectsWithCircle(const Circle* other) const = 0;
}; 