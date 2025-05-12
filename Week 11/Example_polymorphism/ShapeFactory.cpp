#include <random>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

class Shape;
class Rectangle;
class Circle;
class Triangle;

Shape* shapeFactory()
{
    static std::random_device               rd;    
    static std::mt19937                     gen(rd());
    static std::uniform_int_distribution<>  dist(0, 2);

    int r = dist(gen);  //random generator

    switch (r)          
    {
    case 0:  return new Rectangle(3, 4, 6, 8);           
    case 1:  return new Circle(3, 3, 4);             
    default: return new Triangle(1, 1, 2, 2, 3, 3);       
    }
}