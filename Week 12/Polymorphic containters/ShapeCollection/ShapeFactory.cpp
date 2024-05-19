#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>

Shape* shapeFactory()
{
	int figureType; 
	std::cin >> figureType;

	switch (figureType)
	{
	case 1:
	{
		int x1, y1, x2, y2, x3, y3;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		return new Triangle(x1, y1, x2, y2, x3, y3);
	}
	case 2:
	{
		int x1, y1, radius;
		std::cin >> x1 >> y1 >> radius;
		return new Circle(x1, y1, radius);
	}
	case 3:
	{
		int x1, y1, x3, y3;
		std::cin >> x1 >> y1 >> x3 >> y3;
		return new Rectangle(x1, y1, x3, y3);
	}
	default:
		return nullptr;
		break;
	}
}