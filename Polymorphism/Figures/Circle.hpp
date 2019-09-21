#include "Figure.hpp"
class Circle : public Figure
{
	int radius;
public:
	Circle(int x, int y, int r) : Figure(1)
	{
		setPoint(0, x, y);
		if (r < 0)
			r = 0;
		radius = r;
	}
	double getPer()
	{
		return 2 * PI * radius;
	}
	double getArea()
	{
	        return radius*radius*PI;   
	}
};
