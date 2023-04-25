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

public:
	DynamicArrayOfPointers();
	DynamicArrayOfPointers(const DynamicArrayOfPointers& other);
	DynamicArrayOfPointers& operator=(const DynamicArrayOfPointers& other);
	~DynamicArrayOfPointers();

	void pushBack(const A& current);
	void popBack();
	void removeAt(size_t index);
	void setAt(const A& obj, size_t index);

	void pushBack(A&& obj);

	size_t size() const;
	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};
