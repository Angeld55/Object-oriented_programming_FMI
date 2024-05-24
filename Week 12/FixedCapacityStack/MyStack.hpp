
#include <iostream>

template <typename T, const unsigned S>
class MyStack
{
private:
	T arr[S];
	size_t size = 0;
public:

   	void push(const T& obj);
	void push(T&& obj);

	const T& peek() const;
	void pop();

	bool isEmpty() const;
};


template <typename T, const unsigned S>
void MyStack<T,S>::push(const T& obj)
{
	if (size >= S)
		return;
	arr[size++] = obj;
}

template <typename T, const unsigned S>
void MyStack<T,S>::push(T&& obj)
{
	if (size >= S)
		return;
	arr[size++] = std::move(obj);
}

template <typename T, const unsigned S>
const T& MyStack<T,S>::peek() const
{
	if (isEmpty())
		throw std::out_of_range("Error!");

	return arr[size - 1];
}

template <typename T, const unsigned S>
void MyStack<T,S>::pop()
{
	if (isEmpty())
		throw std::out_of_range("Error!");
	size--;
}

template <typename T, const unsigned S>
bool MyStack<T,S>::isEmpty() const
{
	return size == 0;
}
