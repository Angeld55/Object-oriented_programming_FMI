#include <iostream>

template<typename T, typename D>
class PairOfOptionals
{
	T* first;
	D* second;


	void copyFrom(const PairOfOptionals<T, D>& other);
	void free();

public:
	PairOfOptionals();
	PairOfOptionals(const T& leftData, const D& rightData);


	PairOfOptionals(const PairOfOptionals<T,D>& other);
	PairOfOptionals<T, D>& operator=(const PairOfOptionals<T,D>& other);

	~PairOfOptionals();

	void setFirst(const T& firstData);
	void setSecond(const D& firstData);

	const T& getFirst() const;
	const D& getSecond() const;

	void removeFirst();
	void removeSecond();

	bool containsFirst() const;
	bool containsSecond() const;

	bool operator==(const PairOfOptionals<T, D>& rhs) const;
	bool operator!=(const PairOfOptionals<T, D>& rhs) const;


};
template <typename T, typename D>
PairOfOptionals<T, D>::PairOfOptionals() : first(nullptr), second(nullptr){}

template<typename T, typename D>
PairOfOptionals<T, D>::PairOfOptionals(const T& leftData, const D& rightData) : first(nullptr), second(nullptr)
{
	setFirst(leftData);
	setSecond(rightData);
}

template<typename T, typename D>
PairOfOptionals<T, D>::PairOfOptionals(const PairOfOptionals<T, D>& other)
{
	copyFrom(other);
}

template<typename T, typename D>
PairOfOptionals<T, D>& PairOfOptionals<T, D>::operator=(const PairOfOptionals<T, D>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T, typename D>
PairOfOptionals<T, D>::~PairOfOptionals()
{
	free();
}

template<typename T, typename D>
void PairOfOptionals<T, D>::setFirst(const T& firstData)
{
	delete first;
	first = new T(firstData);
}
template<typename T, typename D>
void PairOfOptionals<T, D>::setSecond(const D& secondData)
{
	delete second;
	second = new D(secondData);
}

template<typename T, typename D>
const T& PairOfOptionals<T, D>::getFirst() const
{
	if (!containsFirst())
		throw std::logic_error("No first element");
	return *first;
}
template<typename T, typename D>
const D& PairOfOptionals<T, D>::getSecond() const
{
	if (!containsSecond())
		throw std::logic_error("No second element");
	return *second;
}

template<typename T, typename D>
void PairOfOptionals<T, D>::removeFirst()
{
	delete first;
	first = nullptr;
}
template<typename T, typename D>
void PairOfOptionals<T, D>::removeSecond()
{
	delete second;
	second = nullptr;
}
template<typename T, typename D>
bool PairOfOptionals<T, D>::containsFirst() const
{
	return first != nullptr;
}

template<typename T, typename D>
bool PairOfOptionals<T, D>::containsSecond() const
{
	return second != nullptr;
}

template<typename T, typename D>
void PairOfOptionals<T, D>::copyFrom(const PairOfOptionals<T, D>& other)
{
	if (containsFirst())
		first = new T(*other.first);
	else
		first = nullptr;

	if (containsSecond())
		second = new D(*other.second);
	else
		second = nullptr;
}

template<typename T, typename D>
void PairOfOptionals<T, D>::free()
{
	delete first, second;
}


template<typename S>
bool compareValues(const S* ptr1, const S* ptr2)
{
	return (ptr1 == nullptr && ptr2 == nullptr) || (ptr1 != nullptr && ptr2 != nullptr && *ptr1 == *ptr2);
}

template<typename T, typename D>
bool PairOfOptionals<T, D>::operator==(const PairOfOptionals<T, D>& rhs) const
{
	return compareValues<T>(first, rhs.first) && compareValues<D>(second, rhs.second);
}
template<typename T, typename D>
bool PairOfOptionals<T, D>::operator!=(const PairOfOptionals<T, D>& rhs) const
{
	return !(*this == rhs);
}
