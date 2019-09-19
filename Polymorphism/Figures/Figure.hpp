#include<iostream> 
#include <cmath>

using namespace std;
const double PI = 3.1415;

struct Point
{
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point()
	{
		x = y = 0;
	}
	double getDistTo(const Point& other) const
	{
		return sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
	}
};

class Figure //Този клас е абстрактен - не можем да правим обекти от него.
{

	Point* points;
	int pointsCount;
	void CopyFrom(const Figure& other);
	void Free();
public:
	Figure(int pointsCount);
	Figure(const Figure& other);
	Figure& operator=(const Figure& other);
	~Figure();
	void setPoint(int ind, int x, int y);
	const Point& getPoint(int ind);
	
	//Тези функции са виртуални -> Във всеки неабстрактен наследник трябва да бъдат разписани отделно тези функции.
	//То е и логично - лице на правоъгълник и лице на триъгълник се смята по различен начин, нали?
	// Не можем още тук да дефинираме някаква обща формула, която да върши работа за всички фигури.
	virtual double getPer() = 0;
    	virtual double getArea()= 0;


};

void Figure::CopyFrom(const Figure& other)
{
	points = new Point[other.pointsCount];
	for (int i = 0; i < other.pointsCount; i++)
		points[i] = other.points[i];
	pointsCount = other.pointsCount;
}
void Figure::Free()
{
	delete[] points;
	pointsCount = 0;
}
Figure::Figure(const Figure& other)
{
	CopyFrom(other);
}
Figure& Figure::operator=(const Figure& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Figure::~Figure()
{
	Free();
}
Figure::Figure(int pointsCount)
{
	points = new Point[pointsCount];
	this->pointsCount = pointsCount;
}

void Figure::setPoint(int ind, int x, int y)
{
	if (ind < 0 || ind >= pointsCount)
		return;
	points[ind].x = x;
	points[ind].y = y;
}

const Point& Figure::getPoint(int ind)
{
	if (ind < 0 || ind >= pointsCount)
		throw "Invalid index";
	return points[ind];

}


}











