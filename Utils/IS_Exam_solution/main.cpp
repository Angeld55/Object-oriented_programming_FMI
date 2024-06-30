#include <iostream>
#include <fstream>
#include <stdexcept>

class Set
{
public:
	virtual Set* clone() const = 0;
	virtual bool accepts(unsigned) const = 0;
	virtual ~Set() = default;
};

template <typename T>
class SetByCriteria : public Set
{
public:
	SetByCriteria(const T& cr);
	SetByCriteria(T&& cr);
	Set* clone() const override;
	bool accepts(unsigned) const override;


private:
	T criteria;
};
template <typename T>
SetByCriteria<T>::SetByCriteria(const T& cr) : criteria(cr)
{}

template <typename T>
SetByCriteria<T>::SetByCriteria(T&& cr) : criteria(std::move(cr))
{}

template <typename T>
Set* SetByCriteria<T>::clone() const {
	return new SetByCriteria<T>(*this);
}

template <typename T>
bool SetByCriteria<T>::accepts(unsigned num) const
{
	return criteria(num);
}


class SetOperation : public Set //!!!!!!!!! so we dont write the big twice 
{
protected:
	Set** sets;
	size_t count;
	void copyfrom(const SetOperation& other);
	void free();
	void moveFrom(SetOperation&& other);
public:
	SetOperation(const Set** sets, size_t count);
	SetOperation(Set**&& sets, size_t count);

	SetOperation(const SetOperation& other);
	SetOperation& operator=(const SetOperation& other);

	SetOperation(SetOperation&& other);
	SetOperation& operator=(SetOperation&& other);

	~SetOperation();

};

void SetOperation::copyfrom(const SetOperation& other)
{
	sets = new Set * [other.count];
	for (unsigned i = 0; i < other.count; i++)
		sets[i] = other.sets[i]->clone();

	count = other.count;
}
void SetOperation::free()
{
	for (unsigned i = 0; i < count; i++)
		delete sets[i];
	delete[] sets;
}

void SetOperation::moveFrom(SetOperation&& other)
{
	sets = other.sets;
	count = other.count;

	other.sets = nullptr;
	other.count = 0;
}

SetOperation::SetOperation(const Set** sets, size_t count)
{
	this->sets = new Set * [count];
	for (unsigned i = 0; i < count; i++)
		this->sets[i] = sets[i]->clone();
}
SetOperation::SetOperation(Set**&& sets, size_t count)
{
	this->sets = sets;
	this->count = count;
}

SetOperation::SetOperation(const SetOperation& other) : Set(other)
{
	copyfrom(other);
}
SetOperation& SetOperation::operator=(const SetOperation& other)
{
	if (this != &other)
	{
		Set::operator=(other);
		free();
		copyfrom(other);
	}
	return *this;
}

SetOperation::SetOperation(SetOperation&& other) : Set(std::move(other))
{
	moveFrom(std::move(other));
}

SetOperation& SetOperation::operator=(SetOperation&& other)
{
	if (this != &other)
	{
		Set::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}


SetOperation::~SetOperation()
{
	free();
}



class UnionOfSets : public SetOperation {
public:
	UnionOfSets(const Set** sets, size_t count);
	UnionOfSets(Set**&& sets, size_t count);

	Set* clone() const override;
	bool accepts(unsigned) const override;
};

UnionOfSets::UnionOfSets(const Set** sets, size_t count) : SetOperation(sets, count) {}
UnionOfSets::UnionOfSets(Set**&& sets, size_t count) : SetOperation(std::move(sets), count) {}

Set* UnionOfSets::clone() const {
	return new UnionOfSets(*this);
}

bool UnionOfSets::accepts(unsigned num) const
{
	for (unsigned i = 0; i < count; i++)
	{
		if (sets[i]->accepts(num))
			return true;
	}
	return false;
}


class IntersectionOfSets : public SetOperation {
public:
	IntersectionOfSets(const Set** sets, size_t count);
	IntersectionOfSets(Set**&& sets, size_t count);

	Set* clone() const override;
	bool accepts(unsigned) const override;
};


IntersectionOfSets::IntersectionOfSets(const Set** sets, size_t count) : SetOperation(sets, count) {}
IntersectionOfSets::IntersectionOfSets(Set**&& sets, size_t count) : SetOperation(std::move(sets), count) {}

Set* IntersectionOfSets::clone() const {
	return new IntersectionOfSets(*this);
}

bool IntersectionOfSets::accepts(unsigned num) const
{
	for (unsigned i = 0; i < count; i++)
	{
		if (!sets[i]->accepts(num))
			return false;
	}
	return true;
}

struct ExampleCriteria
{
	bool include = false;
	size_t size = 0;
	int arr[32] = { 0 };

	bool operator()(unsigned n) const
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == n)
			{
				return include;
			}
		}
		return !include;
	}
};


void readFileToArr(const char* fileName, int* arr, size_t& size, size_t maxSize) //we could use the functions for both files (>> skips newlines and spaces)
{
	std::ifstream ifs(fileName);
	if (!ifs)
		return;
	size = 0;
	while (true)
	{
		ifs >> arr[size++];
		if (ifs.eof())
			return;
	}
}
void printSetInInterval(const Set& set, unsigned begin, unsigned end)
{
	for (unsigned i = begin; i < end; i++)
	{
		if (set.accepts(i))
			std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	ExampleCriteria include;
	include.include = true;
	readFileToArr("include.txt", include.arr, include.size, 32);

	ExampleCriteria exclude;
	exclude.include = false;
	readFileToArr("exclude.txt", exclude.arr, exclude.size, 32);

	SetByCriteria<ExampleCriteria> s1(include);
	SetByCriteria<ExampleCriteria> s2(exclude);
	SetByCriteria<bool(*)(unsigned)> s3([](unsigned x) {return x % 2 == 0; });

	const Set** sets = new const Set*[3] {&s1, &s2, & s3};
	IntersectionOfSets s4(sets, 3);

	printSetInInterval(s1, 0, 10);
	printSetInInterval(s2, 0, 10);
	printSetInInterval(s3, 0, 10);
	printSetInInterval(s4, 0, 10);

	delete[] sets;


}
