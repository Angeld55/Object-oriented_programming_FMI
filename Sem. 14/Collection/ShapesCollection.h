#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Rhombus.h"
#include "../Shapes/Square.h"
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
	//
	
	
	void printAreas() const;
	void printPers() const;
	
	ShapesCollection() = default;
	ShapesCollection(const ShapesCollection& other);
	ShapesCollection& operator=(const ShapesCollection& other);

	~ShapesCollection();
};
