#include "ShapeCollection.h"

ShapeCollection::ShapeCollection()
{
	count = 0;
	capacity = 8;

	data = new Shape*[capacity];
}

void ShapeCollection::AddCircle(int x1, int y1, int r)
{
	Circle* current = new Circle(x1, y1, r);
	Add(current);

}
void ShapeCollection::AddTriagnle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Triangle* current = new Triangle(x1, y1, x2, y2, x3, y3);
	Add(current);
}
void ShapeCollection::AddRect(int x1, int y1, int x2, int y2)
{
	Rectangle* current = new Rectangle(x1, y1, x2, y2);
	Add(current);
}
void ShapeCollection::Add(Shape* currentShape)
{
	if (count == capacity)
		Resize();
	data[count++] = currentShape;
}
void ShapeCollection::Free()
{
	for (int i = 0; i < count; i++)
		delete data[i];

	delete[] data;
}
void ShapeCollection::CopyFrom(const ShapeCollection& other)
{
	data = new Shape*[other.count];
	capacity = other.capacity;
	count = other.count;
	for (int i = 0; i < other.count; i++)
		data[i] = other.data[i]->clone();

}
ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	CopyFrom(other);
}
ShapeCollection& ShapeCollection::operator = (const ShapeCollection& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
ShapeCollection::~ShapeCollection()
{
	Free();
}
void ShapeCollection::Resize()
{
	Shape** temp = new Shape*[capacity * 2];
	capacity *= 2;
	for (int i = 0; i < count; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;


}
void ShapeCollection::PrintAllAreas()
{
	for (int i = 0; i < count; i++)
		std::cout << data[i]->getArea() << " ";
	std::cout<<std::endl;
}
void ShapeCollection::PrintAllPers()
{
	for (int i = 0; i < count; i++)
		std::cout << data[i]->getPer() << " ";
	std::cout << std::endl;
}