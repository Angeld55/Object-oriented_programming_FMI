#include "SharedPtr.hpp"

template <typename T>
class WeakPtr
{
	T* data;
	SharedPtr<T>::Counter* counter;
	void copyFrom(const WeakPtr<T>& other);
	void free();

public:
	WeakPtr();

	WeakPtr(SharedPtr<T>& ptr);
	WeakPtr(const WeakPtr<T>& other);
	WeakPtr& operator=(const WeakPtr<T>& other);
	~WeakPtr();

	bool expired() const;
};

template <typename T>
WeakPtr<T>::WeakPtr()
{
	data = nullptr;
	counter = nullptr;
}


template <typename T>
WeakPtr<T>::WeakPtr(SharedPtr<T>& ptr)
{
	data = ptr.data;
	counter = ptr.counter;

	if (counter)
		counter->addWeakPtr();
}

template <typename T>
void WeakPtr<T>::copyFrom(const WeakPtr<T>& other)
{
	data = other.data;
	counter = other.counter;
	if (counter)
		counter->addWeakPtr();
}

template <typename T>
void WeakPtr<T>::free()
{
	if (data == nullptr && counter == nullptr)
		return;

	counter->removeWeakPtr();
	if (counter->weakCount == 0) //also use count is 0
		delete counter;

}

template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr<T>& other)
{
	copyFrom(other);
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
WeakPtr<T>::~WeakPtr()
{
	free();
}

template <typename T>
bool WeakPtr<T>::expired() const
{ 
	return counter && counter->useCount == 0;
}