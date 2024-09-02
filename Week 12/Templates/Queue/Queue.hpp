#include <iostream>
#include <exception>
template <typename T>
class MyQueue
{
	T* data;
	size_t capacity; 
	size_t size;

	size_t get;
	size_t put;

	void resize();

	void moveFrom(MyQueue<T>&& other);
	void copyFrom(const MyQueue<T>& other);
	void free();
public:
	MyQueue();

	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);

	MyQueue(MyQueue<T>&& other) noexcept;
	MyQueue<T>& operator=(MyQueue<T>&& other) noexcept;

	void push(const T& obj);
	void push(T&& obj); 
	void pop();

	const T& peek() const;
	bool isEmpty() const;

	~MyQueue();

};

template <typename T>
MyQueue<T>::MyQueue()
{
	capacity = 4;
	data = new T[capacity];
	size = 0;
	get = put = 0;
}

template <typename T>
void MyQueue<T>::push(const T& obj)
{
	if (size == capacity)
		resize();

	data[put] = obj; //operator=
	(++put) %= capacity;
	size++;
}

template <typename T>
void MyQueue<T>::push(T&& obj)
{
	if (size == capacity)
		resize();

	data[put] = std::move(obj); //move operator =
	(++put) %= capacity;
	size++;
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
	return size == 0;
}


template <typename T>
const T& MyQueue<T>::peek() const
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");

	return data[get];
}

template <typename T>
void MyQueue<T>::pop()
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");
	(++get) %= capacity;
	size--;
}

template <typename T>
void MyQueue<T>::resize()
{
	T* resizedData = new T[capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		resizedData[i] = data[get];
		(++get) %= capacity;
	}
	capacity *= 2;
	delete[] data;
	data = resizedData;
	get = 0;
	put = size;
}


template <typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.capacity; i++)
		data[i] = other.data[i];

	get = other.get;
	put = other.put;

	size = other.size;
	capacity = other.capacity;

}

template <typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	get = other.get;
	put = other.put;

	size = other.size;
	capacity = other.capacity;

	data = other.data;
	other.data = nullptr;

	other.size = other.capacity = 0;
}

template <typename T>
void MyQueue<T>::free()
{
	delete[] data;
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);

}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}


template <typename T>
MyQueue<T>::~MyQueue()
{
	free();
}
