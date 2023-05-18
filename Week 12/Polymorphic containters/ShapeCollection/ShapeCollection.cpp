#include "ShapeCollection.h"
#include <stdexcept>      // std::out_of_range
#include "Rectangle.h"
#include "Circle.h"

#include "Triangle.h"

void ShapeCollection::free()
{
	for (size_t i = 0; i < shapesCount; i++)
		delete shapes[i];  //не се инт. какъв обект е. (вирт дестр)
	delete[] shapes;
}
void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	shapes = new Shape* [other.capacity];
	shapesCount = other.shapesCount;
	capacity = other.capacity;

	for (size_t i = 0; i < shapesCount; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
}

void ShapeCollection::resize()
{
	Shape** newCollection = new Shape * [capacity *= 2];
	for (size_t i = 0; i < shapesCount; i++)
		newCollection[i] = shapes[i]; // !!не правим клониране
	delete[] shapes;
	shapes = newCollection;
}

ShapeCollection::ShapeCollection()
{
	capacity = 8;
	shapesCount = 0;
	shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}
ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShapeCollection::~ShapeCollection()
{
	free();
}

void ShapeCollection::addShape(Shape* shape)
{
	if (shapesCount == capacity)
		resize();
	shapes[shapesCount++] = shape; //we dont make a copy here (it's a private function, called from creation funcions)
}

void ShapeCollection::addRectangle(int x1, int y1, int x3, int y3)
{
	Rectangle* rect = new Rectangle(x1, y1, x3,y3);
	addShape(rect);
}
void ShapeCollection::addCircle(int x1, int y1, int r)
{
	Circle* circlce = new Circle(x1, y1, r);
	addShape(circlce);

}

void ShapeCollection::addTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Triangle* tr = new Triangle(x1, y1,x2,y2, x3, y3);
	addShape(tr);
}

double ShapeCollection::getPerOfFigureByIndex(size_t ind) const
{
	if (ind >= shapesCount)
		throw std::out_of_range("Out of range in shapes collection");
	return shapes[ind]->getPer();
}
double ShapeCollection::getAreaOfFigureByIndex(size_t ind) const
{
	if (ind >= shapesCount)
		throw std::out_of_range("Out of range in shapes collection");
	return shapes[ind]->getArea();
}
double ShapeCollection::getIfPointInShapeByIndex(size_t ind, int x, int y) const
{
	if (ind >= shapesCount)
		throw std::out_of_range("Out of range in shapes collection");
	return shapes[ind]->isPointIn(x, y);
}
