#include  <iostream>

template <typename T>
class Optional
{
	T* objPtr;

	void copyFrom(const Optional<T>& other);
	void free();
		
public:
	Optional();
	Optional(const T& obj);

	Optional(const Optional& other);
	Optional<T>& operator=(const Optional<T>& other);

	~Optional();

	void setValue(const T& obj);
	T getValue() const;

	bool containsValue() const;

	bool operator==(const Optional<T>& other) const;
	bool operator!=(const Optional<T>& other) const;
};

template <typename T>
Optional<T>::Optional() : objPtr(nullptr)
{};

template <typename T>
Optional<T>::Optional(const T& obj)
{
	objPtr = new T(obj);
}

template <typename T>
void Optional<T>::setValue(const T& obj)
{
	delete objPtr;
	objPtr = new T(obj);
}

template <typename T>
T Optional<T>::getValue() const
{
	if (!obj)
		throw std::exception("No value assigned!");
	return *objPtr;
}

template <typename T>
bool Optional<T>::containsValue() const
{
	return objPtr != nullptr;
}

template <typename T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	if (!other.obj)
		objPtr = nullptr;
	else
		objPtr = new T(*other.obj);
}

template <typename T>
void Optional<T>::free()
{
	delete objPtr;
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

template <typename T>
Optional<T>::~Optional()
{
	free();
}

template <typename T>
bool Optional<T>::operator==(const Optional<T>& other) const
{
	return (!objPtr && !other.objPtr) || (objPtr && other.objPtr && *objPtr == *other.objPtr);
}

template <typename T>
bool Optional<T>::operator!=(const Optional<T>& other) const
{
	return !operator==(other);
}
