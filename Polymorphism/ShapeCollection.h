#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class ShapeCollection
{
	Shape** data;
	int count;
	int capacity;

	void Resize();

	void Add(Shape* currentShape);

	void CopyFrom(const ShapeCollection& other);
	void Free();
public:
	ShapeCollection();

	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);
	~ShapeCollection();

	void AddCircle(int x1,int x2,int r);
	void AddTriagnle(int x1,int y1,int x2,int y2,int x3,int y3);
	void AddRect(int x1, int y1, int x2, int y2);

	void PrintAllAreas();
	void PrintAllPers();
};