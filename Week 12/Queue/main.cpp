#include <iostream>
#include <memory>

template <typename T, const unsigned S>
class MyStack
{
private:
	T arr[S];
	size_t size = 0;
public:

	void push(const T& obj)
	{
		if (size >= S)
			return;
		arr[size++] = obj;
	}
	void push(T&& obj)
	{
		if (size >= S)
			return;
		arr[size++] = std::move(obj);
	}

	const T& peek() const
	{
		if (isEmpty())
			throw std::out_of_range("Error!");

		return arr[size - 1];
	}
	void pop()
	{
		if (isEmpty())
			throw std::out_of_range("Error!");
		size--;
	}

	bool isEmpty() const
	{
		return size == 0;
	}
};


template <typename T>
class Optional
{
private:
	T* data = nullptr;

	void copyFrom(const Optional<T>& other)
	{
		if (other.data)
			data = new T(*other.data);//copy constr!!
		else
			data = nullptr;
	}
	void free()
	{
		delete data;
	}
public:

	Optional() = default;
	Optional(const T& value)
	{
		data = new T(value);
	}

	Optional(T&& value)
	{
		data = new T(std::move(value));
	}

	Optional<T>& operator=(const Optional<T>& other)
	{
		return *this;
	}

	const T& operator*() const
	{
		if (!data)
			throw "sfsd";
		return *data;
	}
	T& operator*()
	{
		if (!data)
			throw "sfsd";
		return *data;
	}

	void setValue(const T& value)
	{
		delete data;
		data = new T(value); //copy constr!
	}

	void setValue(T&& value)
	{
		delete data;
		data = new T(std::move(value)); //move constr!
	}
	void reset()
	{
		delete data;
		data = nullptr; 
	}
	operator bool() const
	{
		return data != nullptr;
	}
};


template <typename T>
class SharedPtr
{
	T* data;
	unsigned* pointersCount;

	void free()
	{
		if (*pointersCount == 1)
		{
			delete data;
			delete pointersCount;
		}
		else
			(*pointersCount)--;
	}

	void copyFrom(const SharedPtr<T>& other)
	{
		data = other.data;
		pointersCount = other.pointersCount;
		(*pointersCount)++;
	}

public:
	SharedPtr(T* data)
	{
		this->data = data;
		pointersCount = new unsigned(1);
	}

	SharedPtr(const SharedPtr<T>& other)
	{
		data = other.data;
		pointersCount = other.pointersCount;
		(*pointersCount)++;
	}

	SharedPtr& operator=(const SharedPtr<T>& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	const T& operator*() const
	{
		return data;
	}
	
	T& operator*()
	{
		return data;
	}

	~SharedPtr()
	{
		if (*pointersCount == 1)
		{
			delete data;
			delete pointersCount;
		}
		else
			(*pointersCount)--;
	}
};

template <class T, class D>
class Pair
{
	T first;
	D second;

public:
	Pair(const T& first, const D& second) : first(first), second(second)
	{}


	Pair(T&& first, D&& second) : first(std::move(first)), second(std::move(second))
	{}
	const T& getFirst() const
	{
		return first;
	}
	const D& getSecond() const
	{
		return second;
	}

	void setFirst(const T& first)
	{
		this->first = first;
	}

	void setFirst(T&& first)
	{
		this->first = std::move(first);
	}


	void setSecond(const D& second)
	{
		this->second = second;
	}

	void setSecond(D&& second)
	{
		this->second = std::move(second);
	}


};

template <typename T, typename D, typename K>
class Tripple
{
	Pair<Pair<T, D>, K> data;
};

int main()
{
	Pair<int, char> qq(3, 'D');


}
