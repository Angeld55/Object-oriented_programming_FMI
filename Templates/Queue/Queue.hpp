#ifndef QUEUE_HDR
#define QUEUE_HDR

#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
	T * arr;
	int capacity;
	int count;

	int whereToPut;
	int whereToGet;
	void Resize();
	void CopyFrom(const Queue<T>& other);
	void Free();

public:
	Queue();
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);
	~Queue();

	bool isEmpty() const;
	void Push(T el);
	T Pop();
	T& Peek();
};

template <typename T>
void Queue<T>::Resize() {
	T* temp = new T[capacity * 2];
	for (int i = 0; i < capacity; ++i)
		temp[i] = Pop();
	whereToGet = 0;
	whereToPut = capacity;
	count = capacity;
	capacity *= 2;
	delete[] arr;
	arr = temp;
}

template <typename T>
void Queue<T>::CopyFrom(const Queue<T>& other) {
	arr = new T[other.capacity];
	for (int i = 0; i < other.count; ++i)
		arr[i] = other.arr[i];
	count = other.count;
	capacity = other.capacity;
	whereToPut = other.whereToPut;
	whereToGet = other.whereToGet;
}

template <typename  T>
void Queue<T>::Free() {
	delete[] arr;
	count = capacity = 0;
}

template <typename T>
Queue<T>::Queue() {
	arr = new T[4];
	capacity = 4;
	count = 0;
	whereToPut = 0;
	whereToGet = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
	CopyFrom(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue() {
	Free();
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return count == 0;
}

template <typename T>
void Queue<T>::Push(T el) {
	if (count == capacity)
		Resize();
	arr[whereToPut] = el;
	(whereToPut += 1) %= capacity;
	count++;
}

template <typename T>
T Queue<T>::Pop() {
	if (count == 0)
		throw "Queue is empty";
	T elToReturn = arr[whereToGet];
	count--;
	(whereToGet += 1) %= capacity;
	return  elToReturn;
}

template <typename T>
T& Queue<T>::Peek() {
	if (isEmpty())
		throw std::logic_error("empty queue");
	return arr[whereToGet];
}

#endif // !QUEUE_HDR
