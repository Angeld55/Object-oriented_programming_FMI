#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(int x1, int y1, int x3, int y3);

	double getPer();
	double getArea();

	Shape* clone();
};