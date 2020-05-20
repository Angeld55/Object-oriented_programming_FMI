#include "Shape.h"

const double PI = 3.14;
class Circle : public Shape
{

	int radius;
public:
	Circle(int x, int y, int radius);

	double getArea();
	double getPer();

	Shape* clone();

};