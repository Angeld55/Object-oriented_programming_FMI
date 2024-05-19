#include "Shape.h"

class ShapeCollection
{
public:
	ShapeCollection();

	ShapeCollection(const ShapeCollection& other);
	ShapeCollection(ShapeCollection&& other) noexcept;

	ShapeCollection& operator=(const ShapeCollection&);
	ShapeCollection& operator=(ShapeCollection&&) noexcept;

	~ShapeCollection() noexcept;

	void addFigure(Shape* shape); //will take the ownership of the object  

	void addFigure(const Shape& shape);

	double getAreaByIndex(unsigned ind) const;
	double getPerByIndex(unsigned ind) const;
	double getIsPointInByIndex(unsigned ind, int x, int y) const;

	const Shape* operator[](unsigned) const;
	unsigned getSize() const;

private:

	void resize(size_t newCap);
	void moveFrom(ShapeCollection&& other);
	void copyFrom(const ShapeCollection& other);
	void free();

	Shape** data = nullptr;
	size_t capacity = 0;
	size_t size = 0;;
};
