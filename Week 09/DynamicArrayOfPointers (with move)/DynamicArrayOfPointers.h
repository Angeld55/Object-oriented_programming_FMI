#include <iostream>

struct A
{
	int x = 3;
	int y = 2;
};

class DynamicArrayOfPointers
{
	A** _data;
	size_t _capacity; //колко е големината на масива от указатели
	size_t _count = 0; //колко елемента са добавени

	void free();
	void copyFrom(const DynamicArrayOfPointers& other);
	void resize(size_t newCap);

	void moveFrom(DynamicArrayOfPointers&& other);

	int getFirstFreeIndex() const; //Better solution will be to store a variable with the first free index
public:
	DynamicArrayOfPointers();
	DynamicArrayOfPointers(const DynamicArrayOfPointers& other);
	DynamicArrayOfPointers& operator=(const DynamicArrayOfPointers& other);
	~DynamicArrayOfPointers();

	DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept;
	DynamicArrayOfPointers& operator=(DynamicArrayOfPointers&& other) noexcept;

	void addAtFirstFreeIndex(const A& current);
	void addAtFirstFreeIndex(A&& obj);

	bool containsAt(unsigned ind) const;
	void popBack();
	void removeAt(size_t index);

	void setAtIndex(const A& obj, size_t index);
	void setAtIndex(A&& obj, size_t index);


	size_t size() const;
	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};
