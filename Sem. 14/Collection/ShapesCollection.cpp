#include "ShapesCollection.h"

void ShapesCollection::addCircle(double x, double y, double radius)
{
	Circle* ptr = new Circle(x, y, radius);
	collection.push_back(ptr);
}
void ShapesCollection::addRectangle(double x1, double y1, double x3, double y3)
{
	Rectangle* ptr = new Rectangle(x1, y1, x3, y3);
	collection.push_back(ptr);
}
void ShapesCollection::addTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	Triangle* ptr = new Triangle(x1, y1, x2, y2, x3, y3);
	collection.push_back(ptr);
}
void ShapesCollection::addRhombus(double x1, double y1, double x2, double y2)
{
	collection.push_back(new Rhombus(x1, y1, x2, y2));
}

void ShapesCollection::addSquare(double x1, double y1, double sideLength)
{
	collection.push_back(new Square(x1, y1, sideLength));
}

void ShapesCollection::printAreas() const
{
	for (int i = 0; i < collection.size(); i++)
		std::cout << collection[i]->getArea() << " " << std::endl;
}
void ShapesCollection::printPers() const
{
	for (int i = 0; i < collection.size(); i++)
		std::cout << collection[i]->getPer() << " " << std::endl;
}

void ShapesCollection::copyFrom(const ShapesCollection& other)
{
	for (int i = 0; i < other.collection.size(); i++)
		collection.push_back(other.collection[i]->clone());
}
void ShapesCollection::free()
{
	for (int i = 0; i < collection.size(); i++)
		delete collection[i];
	collection.clear();
}

ShapesCollection::ShapesCollection(const ShapesCollection& other)
{
	copyFrom(other);
}
ShapesCollection& ShapesCollection::operator= (const ShapesCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShapesCollection::~ShapesCollection()
{
	free();
}
