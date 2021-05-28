#include "Rhombus.h"
#include "Rectangle.h"

class Square : public Rhombus, public Rectangle
{
public:
	Square(double x, double y, double sideLength);

	double getArea() const override;
	double getPer() const override;

	Shape* clone() const override;
};