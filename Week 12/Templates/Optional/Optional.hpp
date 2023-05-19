#pragma once
#include <iostream>
#include <exception>
template <typename T>
class Optional
{	
	//TBI move and operator*
	T* data; //DYN MEM

	void copyFrom(const Optional<T>& other);
	void free();
public:
	Optional();
	Optional(const T& obj);

	Optional(const Optional<T>& other);
	Optional<T>& operator=(const Optional<T>& other);

	bool containsData() const;
	const T& getData() const;
	void setData(const T& el);
	void clear();

	
};

template <typename T>
Optional<T>::Optional() : data(nullptr)
{}

template <typename T>
Optional<T>::Optional(const T& obj) : data(nullptr)
{
	setData(obj);
}

template <typename T>
bool Optional<T>::containsData() const
{
	return data != nullptr;
}

template <typename T>
const T& Optional<T>::getData() const
{
	if (!containsData())
		throw std::logic_error("No data in optional");
	return *data;
}

template <typename T>
void Optional<T>::setData(const T& el)
{
	delete data;
	data = new T(el);// copy const; 
}

template <typename T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	if (other.containsData())
		data = new T(*other.data);
	else
		data = nullptr;
}

template <typename T>
void Optional<T>::free()
{
	delete data;
}

template <typename T>
void Optional<T>::clear()
{
	free();
	data = nullptr;
}


template <typename T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}


template <typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
