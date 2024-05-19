
template <typename T>
class Queue
{
public:
	Queue();

	void push(const T& obj);
	void push(T&& obj);

	void pop();
	const T& peek(); //погледни обекта, който ще се премахне при pop

	size_t getSize() const;
	bool isEmpty() const;
private:
	T* data = nullptr; //
	size_t size = 0;
	size_t capacity = 8;

	size_t getInd = 0; //last added el
	size_t putInd = 0; //first free ind

	void resize(size_t newCap);
};

template <typename T>
Queue<T>::Queue()
{
	capacity = 8;
	size = 0;
	data = new T[capacity]; ///def constr
}

template <typename T>
void Queue<T>::push(const T& obj)
{
	if (size == capacity)
		resize();
	data[putInd] = obj; //op=
	(++putInd) %= capacity;
	size++;
}

template <typename T>
void Queue<T>::push(T&& obj)
{
	if (size == capacity)
		resize();
	data[putInd] = std::move(obj); //move op=
	(++putInd) %= capacity;
	size++;
}

template <typename T>
const T& Queue<T>::peek()
{
	if (isEmpty())
		throw "qweqwe";
	return data[getInd];
}

template <typename T>
void Queue<T>::pop()
{
	if (isEmpty())
		throw "qweqwe";
	(++getInd) %= capacity;
	size--;
}

template <typename T>
void Queue<T>::resize(size_t newCap)
{
	T* newData = new T[newCap];
	for (int i = 0; i < size; i++)
	{
		newData[i] = std::move(data[getInd]); 
		(++getInd) %= capacity;
	}
	delete[] data;
	data = newData;
	capacity = newCap;
	getInd = 0;
	putInd = size;
}

