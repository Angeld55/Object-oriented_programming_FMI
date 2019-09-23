#include "point.hpp"

class Triangle
{
public:
	Point p1;
	Point p2;
	Point p3;
	//Кой конструктор е по-добре да ползваме и защо?
	Triangle(Point p1, Point p2, Point p3);
	Triangle(int x1,int y1,int x2,int y2,int x3,int y3);

	double getPer();


};
Triangle::Triangle(Point p1, Point p2, Point p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}
Triangle::Triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
	p3.x = x3;
	p3.y = y3;
}
// Използваме вече дефинираните функции, без да се интересуваме от тяхната реализация
double Triangle::getPer()
{
	return p1.DistTo(p2) + p2.DistTo(p3) + p3.DistTo(p1);
}
