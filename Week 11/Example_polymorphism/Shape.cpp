#include "Shape.h"
#include <assert.h>

Shape::Shape(size_t pointsCount) : pointsCount(pointsCount)
{
	points = new point[pointsCount]; // [0,0], [0,0]....
}

void Shape::copyFrom(const Shape& other)
{
	points = new point[other.pointsCount];
	
	for (int i = 0; i < other.pointsCount; i++)
		points[i] = other.points[i];
	
	pointsCount = other.pointsCount;
}
void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	other.points = nullptr;

	pointsCount = other.pointsCount;
}
void Shape::free()
{
	delete[] points;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}
Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator= (const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Shape::~Shape()
{
	free();
}

const Shape::point& Shape::getPointAtIndex(size_t index) const
{
	if (index >= pointsCount)
		throw std::exception("Invalid point index!");

	return  points[index];
}

void Shape::setPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex >= pointsCount)
		throw std::exception("Invalid point index!");

	points[pointIndex] = point(x, y);
}

double Shape::getPer() const //we sum the distance of all consecutive points
{
	assert(pointsCount >= 3);

	double per = 0;
	for (int i = 0; i < pointsCount - 1; i++)
		per += points[i].getDist(points[i + 1]);
	return per + points[pointsCount - 1].getDist(points[0]);
}
