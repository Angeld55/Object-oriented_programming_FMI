#include <iostream>

template <typename T>
class UniquePointer
{
	T* ptr;
public:
	UniquePointer(T* ptr);

	UniquePointer(const UniquePointer<T>&) = delete;
	UniquePointer<T>& operator=(const UniquePointer<T>&) = delete;

	UniquePointer(UniquePointer<T>&&) noexcept;
	UniquePointer<T>& operator=(UniquePointer<T>&&) noexcept;

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

	~UniquePointer();
};

template <typename T>
UniquePointer<T>::UniquePointer(T* ptr) : ptr(ptr)
{}

template <typename T>
UniquePointer<T>::UniquePointer(UniquePointer<T>&& other) noexcept
{
	ptr = other.ptr;
	other.ptr = nullptr;
}
template <typename T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T>&& other) noexcept
{
	if (this != &other)
	{
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

template <typename T>
T& UniquePointer<T>::operator*()
{
	return *ptr;
}

template <typename T>
const T& UniquePointer<T>::operator*() const
{
	return *ptr;
}


template <typename T>
T* UniquePointer<T>::operator->()
{
	return ptr;
}

template <typename T>
const T* UniquePointer<T>::operator->() const
{
	return ptr;
}

template <typename T>
UniquePointer<T>::~UniquePointer()
{
	delete *ptr;
}


