#pragma once
#include <iostream>

class Nvector
{
private:
	int* data;
	size_t size;

	void copyFrom(const Nvector& other);
	void free();

public:
	Nvector(size_t size);

	Nvector(const Nvector& other);
	Nvector& operator=(const Nvector& other);
	~Nvector();

	Nvector& operator+=(const Nvector& other);
	Nvector& operator-=(const Nvector& other);

	Nvector& operator*=(size_t scalar);

	int& operator[](size_t); //get set
	 
	int operator[](size_t) const; // get

	void print();

	size_t operator~() const;//ize;

	friend std::ostream& operator<<(std::ostream& os, const Nvector& v);
	friend std::istream& operator>>(std::istream&, Nvector& v);
};

const Nvector operator+(const Nvector& lhs, const Nvector& rhs);
const Nvector operator-(const Nvector& lhs, const Nvector& rhs);

const Nvector operator*(const Nvector& lhs, size_t scalar);
//So it could be commutative. Is there a better way?
const Nvector operator*(size_t scalar, const Nvector& lhs);

//are parallel
bool operator||(const Nvector& lhs, const Nvector& rhs);


//scalar product
size_t operator%(const Nvector& lhs, const Nvector& rhs);

//are perpendicular
bool operator||(const Nvector& lhs, const Nvector& rhs);
