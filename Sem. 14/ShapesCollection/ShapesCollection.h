#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Square.h"
#include <vector>

class ShapesCollection
{
	std::vector<Shape*> collection;

	void free();
	void copyFrom(const ShapesCollection& other);

public:

	//factory

	void addCircle(double x, double y, double radius);
	void addRectangle(double x1, double y1, double x3, double y3);
	void addTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	void addRhombus(double x1, double y1, double x2, double y2);
	void addSquare(double x1, double y2, double sideLength);
	
	void printAreas();
	void printPers();
	
	ShapesCollection() = default;
	ShapesCollection(const ShapesCollection& other);
	ShapesCollection& operator=(const ShapesCollection& other);

	~ShapesCollection();
};