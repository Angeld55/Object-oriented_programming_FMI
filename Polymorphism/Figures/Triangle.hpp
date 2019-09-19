#include "Figure.hpp"
class Triangle
{
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) :Figure(3)
	{
		setPoint(0, x1, y1);
		setPoint(1, x2, y2);
		setPoint(2, x3, y3);
	}
	double getSide(int side)
	{
	    return getPoint(side).getDistTo(getPoint((side+1)%3));
	}
	double getPer()
	{
		return getSide(0)+getSide(1)+getSide(2);
	}
	double getArea()
	{
	    //Херонова формула
	   double halfP = getPer()/2; 
	   return sqrt(halfP * (halfP-getSide(0))*(halfP-getSide(1))*(halfP-getSide(2)));
	}
};
