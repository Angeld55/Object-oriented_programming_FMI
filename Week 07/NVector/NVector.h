#pragma once
#include <iostream>

class NVector
{
private:
	int* data;
	size_t size;

	void copyFrom(const NVector& other);
	void free();

public:
	NVector(size_t size);

	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();


	NVector& operator+=(const NVector& other);
	NVector& operator-=(const NVector& other);


	NVector& operator*=(size_t scalar);

	int& operator[](size_t); //get set
	int operator[](size_t) const; // get


	size_t operator~() const;// size;

	friend std::ostream& operator<<(std::ostream& os, const NVector& v);
	friend std::istream& operator>>(std::istream&, NVector& v);
};

NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator-(const NVector& lhs, const NVector& rhs);


//So it could be commutative:
NVector operator*(const NVector& lhs, size_t scalar);
NVector operator*(size_t scalar, const NVector& lhs);


//are parallel
bool operator||(const NVector& lhs, const NVector& rhs);


//scalar product
size_t operator%(const NVector& lhs, const NVector& rhs);


//are perpendicular
bool operator|=(const NVector& lhs, const NVector& rhs);
