#include "Figure.hpp"
class Rectangle : public Figure
{
public:
	Rectangle(int x1, int y1, int x2, int y2) : Figure(4)
	{
		setPoint(0, x1, y1);
		setPoint(1, x2, y1);
		setPoint(2, x2, y2);
		setPoint(3, x1, y2);
	}
	double getPer()
	{
		return 2 * (getPoint(0).getDistTo(getPoint(1)) + getPoint(0).getDistTo(getPoint(3)));
	}
	double getArea()
	{
	 return getPoint(0).getDistTo(getPoint(1))* getPoint(1).getDistTo(getPoint(2));   
	}
};