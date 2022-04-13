#ifndef VECTOR_HEADER
#define VECTOR_HEADER

class vector {
private:
	int* data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const vector&);
	void resize(); // x2 memory
public:
	vector();
	vector(const vector&);
	
	vector& operator=(const vector&);

	size_t getSize() const;
	void push_back(int);

	int& operator[](size_t);
	const int operator[](size_t) const;

	~vector();
};

#endif

