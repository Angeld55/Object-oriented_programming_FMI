#pragma once
#include <iostream>

template <typename T>
class Queue
{
	T* data;
	size_t capacity;
	size_t count;

	size_t head; //where to get
	size_t tail; //last added element;

	void resize(size_t newCapacity);

	void copyFrom(const Queue<T>& other);
	void free();
public:
	Queue();

	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);

	void enqueue(const T& obj);
	T dequeue();

	size_t getCount();
	size_t isEmpty();

	~Queue();
};

template <typename T>
Queue<T>::Queue()
{
	capacity = 4;
	data = new T[capacity];

	count = 0;
	head = tail = 0;
}



template <typename T>
void Queue<T>::enqueue(const T& obj)
{
	if (count == capacity)
		resize(capacity * 2);
	if (count != 0)
		tail++;

	tail %= capacity; //so we don't get an out of range exception

	data[tail] = obj;

	count++;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (count == 0)
		throw std::exception("The collection is empty!");

	T toReturn = data[head];
	(++head) %= capacity;

	count--;

	return toReturn;
}

template <typename T>
size_t Queue<T>::getCount()
{
	return count;
}

template <typename T>
size_t Queue<T>::isEmpty()
{
	return getCount() == 0;
}

template <typename T>
void Queue<T>::resize(size_t newCapacity)
{
	T* newData = new T[newCapacity];

	for (int i = 0, ind = head; i < count; i++, (++ind) %= capacity)
		newData[i] = data[ind];

	delete[] data;
	capacity = newCapacity;
	data = newData;

	head = 0;
	tail = count - 1;
}

template <typename T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.capacity; i++)
		data[i] = other.data[i];

	head = other.head;
	tail = other.tail;

	count = other.count;
	capacity = other.capacity;

}

template <typename T>
void Queue<T>::free()
{
	delete[] data;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
	copyFrom(other);

}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	free();
}
