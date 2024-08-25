#include <iostream>

template <typename T>
class UniquePointer
{
	T* ptr;
public:
	UniquePointer(T* ptr);

	UniquePointer(const UniquePointer&) = delete;
	UniquePointer& operator=(const UniquePointer&) = delete;

	UniquePointer(UniquePointer&&) noexcept;
	UniquePointer& operator=(UniquePointer&&) noexcept;

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
	delete ptr;
}
