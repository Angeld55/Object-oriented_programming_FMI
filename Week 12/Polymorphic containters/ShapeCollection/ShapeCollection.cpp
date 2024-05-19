#include "ShapeCollection.h"


ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}
ShapeCollection::ShapeCollection(ShapeCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

ShapeCollection& ShapeCollection::operator= (const ShapeCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ShapeCollection::~ShapeCollection() noexcept
{
	free();
}

ShapeCollection::ShapeCollection()
{
	capacity = 8;
	data = new Shape * [capacity] {nullptr};
	size = 0;
}
void ShapeCollection::moveFrom(ShapeCollection&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}
void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	data = new Shape * [other.capacity];

	for (int i = 0; i < other.size; i++)
		data[i] = other.data[i]->clone();

	size = other.size;
	capacity = other.capacity;
}

void ShapeCollection::free()
{
	for (int i = 0; i < size; i++)
		delete data[i]; // correct destr (virtual ~Shape())
	delete[] data;
}

void ShapeCollection::addFigure(Shape* shape)
{
	if (size == capacity)
		resize(capacity * 2);
	data[size++] = shape; ///pray for shape to be a dynamic object
	shape = nullptr;
}

void ShapeCollection::addFigure(const Shape& shape)
{
	Shape* cloned = shape.clone();
	addFigure(cloned);
}

void ShapeCollection::resize(size_t newCap)
{
	Shape** newData = new Shape * [newCap];
	for (int i = 0; i < size; i++)
		newData[i] = data[i];
	delete[] data;
	data = newData;
	capacity = newCap;
}


double ShapeCollection::getAreaByIndex(unsigned ind) const
{
	return data[ind]->getArea();
}
double ShapeCollection::getPerByIndex(unsigned ind) const
{
	return data[ind]->getPer();

}
double ShapeCollection::getIsPointInByIndex(unsigned ind, int x, int y) const
{
	return data[ind]->isPointIn(x, y);
}

unsigned ShapeCollection::getSize() const
{
	return size;
}


const Shape* ShapeCollection::operator[](unsigned ind) const
{
	return data[ind];
}
