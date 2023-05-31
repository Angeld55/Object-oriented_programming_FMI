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


class SetOperation : public Set
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

SetOperation::SetOperation(const SetOperation& other)
{
	copyfrom(other);
}
SetOperation& SetOperation::operator=(const SetOperation& other)
{
	if (this != &other)
	{
		free();
		copyfrom(other);
	}
	return *this;
}

SetOperation::SetOperation(SetOperation&& other)
{
	moveFrom(std::move(other));
}

SetOperation& SetOperation::operator=(SetOperation&& other)
{
	if (this != &other)
	{
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
	UnionOfSets(const Set**&& sets, size_t count);

	Set* clone() const override;
	bool accepts(unsigned) const override;
};

UnionOfSets::UnionOfSets(const Set** sets, size_t count) : SetOperation(sets, count) {}
UnionOfSets::UnionOfSets(const Set**&& sets, size_t count) : SetOperation(std::move(sets), count) {}

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
	IntersectionOfSets(const Set**&& sets, size_t count);

	Set* clone() const override;
	bool accepts(unsigned) const override;
};


IntersectionOfSets::IntersectionOfSets(const Set** sets, size_t count) : SetOperation(sets, count) {}
IntersectionOfSets::IntersectionOfSets(const Set**&& sets, size_t count) : SetOperation(std::move(sets), count) {}

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

class BaseCriteria {
protected:
	unsigned numbers[32];
	uint16_t count;

public:
	BaseCriteria(const unsigned* arr, uint16_t count);
	virtual bool operator()(unsigned number) const = 0;
};

BaseCriteria::BaseCriteria(const unsigned* numbers, uint16_t count) : count(count) {
	for (size_t i = 0; i < count; i++) {
		this->numbers[i] = numbers[i];
	}
}

class FiniteSetCriteria :public BaseCriteria {
public:
	FiniteSetCriteria(const unsigned* numbers, uint16_t count);
	bool operator()(unsigned number) const override;
};

FiniteSetCriteria::FiniteSetCriteria(const unsigned* numbers, uint16_t count) : BaseCriteria(numbers, count) { }

bool FiniteSetCriteria::operator()(unsigned number) const {
	for (size_t i = 0; i < count; i++) {
		if (numbers[i] == number) {
			return true;
		}
	}

	return false;
}

class NotDividedByCriteria :public BaseCriteria {
public:
	NotDividedByCriteria(const unsigned* numbers, uint16_t count);
	bool operator()(unsigned number) const override;
};

NotDividedByCriteria::NotDividedByCriteria(const unsigned* numbers, uint16_t count) : BaseCriteria(numbers, count) {}

bool NotDividedByCriteria::operator()(unsigned number) const {
	for (size_t i = 0; i < count; i++) {
		if (number % numbers[i] == 0) {
			return false;
		}
	}

	return true;
}

class DividedByOnlyOneCriteria :public BaseCriteria {
public:
	DividedByOnlyOneCriteria(const unsigned* numbers, uint16_t count);
	bool operator()(unsigned number) const override;
};

DividedByOnlyOneCriteria::DividedByOnlyOneCriteria(const unsigned* numbers, uint16_t count) : BaseCriteria(numbers, count) {}

bool DividedByOnlyOneCriteria::operator()(unsigned number) const {
	uint16_t dividedBy = 0;
	for (size_t i = 0; i < count; i++) {
		if (number % numbers[i] == 0 && ++dividedBy == 2) {
			return false;
		}
	}

	return dividedBy == 1;
}

SetByCriteria<FiniteSetCriteria>* createFiniteSet(std::ifstream& in) {
	uint16_t count;
	unsigned numbers[32];
	in.read((char*)&count, sizeof(uint16_t));
	in.read((char*)numbers, count * sizeof(unsigned));

	return new SetByCriteria<FiniteSetCriteria>(FiniteSetCriteria(numbers, count));
}

SetByCriteria<NotDividedByCriteria>* createNotDividedByAnySet(std::ifstream& in) {
	uint16_t count;
	unsigned numbers[32];
	in.read((char*)&count, sizeof(uint16_t));
	in.read((char*)numbers, count * sizeof(unsigned));

	return new SetByCriteria<NotDividedByCriteria>(NotDividedByCriteria(numbers, count));
}

SetByCriteria<DividedByOnlyOneCriteria>* createNotDividedByOnlyOneSet(std::ifstream& in) {
	uint16_t count;
	unsigned numbers[32];
	in.read((char*)&count, sizeof(uint16_t));
	in.read((char*)numbers, count * sizeof(unsigned));

	return new SetByCriteria<DividedByOnlyOneCriteria>(DividedByOnlyOneCriteria(numbers, count));
}

Set* setFactory(const char* fileName);

Set** readSets(std::ifstream& in, uint16_t& count) {
	in.read((char*)&count, sizeof(uint16_t));

	Set** sets = new Set * [count];

	char buffer[1024];
	for (size_t i = 0; i < count; i++) {
		in.getline(buffer, 1024, '\0');
		sets[i] = setFactory(buffer);
	}

	return sets;
}

void deleteSets(Set** sets, uint16_t count) {
	for (size_t i = 0; i < count; i++) {
		delete sets[i];
	}
	delete[] sets;
}


//TBI ->
UnionOfSets* createUnionOfSets(std::ifstream& in) {
	uint16_t count;
	Set** setsToUnite = readSets(in, count);
	//auto result = new UnionOfSets(setsToUnite, count);
	deleteSets(setsToUnite, count);
	return nullptr;
}

IntersectionOfSets* createIntersectionOfSets(std::ifstream& in) {
	uint16_t count;
	Set** setsToIntersect = readSets(in, count);
	//auto result = new IntersectionOfSets(setsToIntersect, count);
	deleteSets(setsToIntersect, count);
	return nullptr;
}

Set* setFactory(const char* fileName) {
	std::ifstream in(fileName, std::ios::binary);

	if (!in.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	uint16_t mode;
	in.read((char*)&mode, sizeof(uint16_t));

	switch (mode) {
	case 0: return createFiniteSet(in); break;
	case 1: return createNotDividedByAnySet(in); break;
	case 2: return createNotDividedByOnlyOneSet(in); break;
	case 3: return createIntersectionOfSets(in); break;
	case 4: return createUnionOfSets(in); break;
	default: throw std::runtime_error("Invalid mode"); break;
	}
}

void createFiniteFile(const char* name) {
	std::ofstream out(name, std::ios::binary);
	uint16_t mode = 0;
	uint16_t count = 7;
	out.write((char*)&mode, sizeof(uint16_t));
	out.write((char*)&count, sizeof(uint16_t));

	unsigned arr[] = { 1, 3, 4, 6, 2, 8, 9};
	out.write((char*)arr, count * sizeof(unsigned));
}

void createT1(const char* name) {
	std::ofstream out(name, std::ios::binary);
	uint16_t mode = 1;
	uint16_t count = 2;
	out.write((char*)&mode, sizeof(uint16_t));
	out.write((char*)&count, sizeof(uint16_t));

	unsigned arr[] = { 4, 6 };
	out.write((char*)arr, count * sizeof(unsigned));
}

void createT2(const char* name) {
	std::ofstream out(name, std::ios::binary);
	uint16_t mode = 2;
	uint16_t count = 3;
	out.write((char*)&mode, sizeof(uint16_t));
	out.write((char*)&count, sizeof(uint16_t));

	unsigned arr[] = { 2, 3, 5 };
	out.write((char*)arr, count * sizeof(unsigned));
}

void testSet(const char* fileName) {
	Set* set = setFactory(fileName);

	for (size_t i = 0; i < 10; i++) {
	    if(set->accepts(i))
		    std::cout << i << " ";
	}
	std::cout << std::endl;

	delete set;
}

int main() {
	const char* t0 = "t0.dat";
	const char* t1 = "t1.dat";
	const char* t2 = "t2.dat";
	createFiniteFile(t0);
	createT1(t1);
	createT2(t2);

	testSet(t0);
	testSet(t1);
	testSet(t2);
}
