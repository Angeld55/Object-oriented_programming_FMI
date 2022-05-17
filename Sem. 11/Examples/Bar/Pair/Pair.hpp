#pragma once

template<typename T, typename D>
class Pair
{
	T first;
	mutable D second; // For Drinks task!!
public:
	Pair() = default;
	Pair(const T& first, const D& second);
	const T& getFirst() const;
	const D& getSecond() const;

	void setFirst(const T& newValue);
	void setSecond(const D& newValue) const ;
};

template<typename T, typename D>
Pair<T,D>::Pair(const T& first, const D& second) : first(first), second(second)
{}

template<typename T, typename D>
const T& Pair<T, D>::getFirst() const
{
	return first;
}
template<typename T, typename D>
const D& Pair<T, D>::getSecond() const
{
	return second;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(const T& newValue)
{
	first = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setSecond(const D& newValue) const
{
	second = newValue;
}