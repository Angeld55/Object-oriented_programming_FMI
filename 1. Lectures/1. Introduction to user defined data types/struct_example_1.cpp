#include <iostream>

struct Point
{
	int x;
	int y;
};

double getDist(const Point& p1, const Point& p2)
{
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

struct Line
{
	Point p1;
	Point p2;
};

double getSlope(const Line& myLine)
{
	double dx = myLine.p1.x - myLine.p2.x;
	double dy = myLine.p1.y - myLine.p2.y;

	return dy / dx;

}

bool areParallel(const Line& line1, const Line& line2)
{
	return abs(getSlope(line1) - getSlope(line2)) <= 0.0001;
}


int main()
{
	Line l1{1,2,3,4};
	Line l2{0,1,2,3};
	
	std::cout << areParallel(l1, l2);
	
}
