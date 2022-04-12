#include "Nvector.h"

Nvector::Nvector(size_t n) : size(n)
{
	data = new int[n];

	for (int i = 0; i < n; i++)
		data[i] = 0;
}

Nvector::Nvector(const Nvector& other)
{
	copyFrom(other);
}

Nvector& Nvector::operator=(const Nvector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Nvector::~Nvector()
{
	free();
}

void Nvector::copyFrom(const Nvector& other)
{
	size = other.size;
	data = new int[size];

	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}
void Nvector::free()
{
	delete[] data;
	size = 0;
}



//v += v1;
Nvector& Nvector::operator+=(const Nvector& other)
{
	if (size != other.size)
		throw "The vectors should have the same size!";

	for (int i = 0; i < size; i++)
		data[i] += other.data[i];

	return *this;
}

Nvector& Nvector::operator-=(const Nvector& other)
{
	if (size != other.size)
		throw "The vectors should have the same size!";

	for (int i = 0; i < size; i++)
		data[i] -= other.data[i];
	
	return *this;
}

const Nvector operator+(const Nvector& lhs, const Nvector& rhs)
{
	Nvector lhsCopy(lhs);
	lhsCopy += rhs;

	return lhsCopy;
}

const Nvector operator-(const Nvector& lhs, const Nvector& rhs)
{
	Nvector lhsCopy(lhs);
	lhsCopy -= rhs;

	return lhsCopy;
}

int& Nvector::operator[](size_t index)
{
	if (index >= size)
		throw "Invalid index";

	return data[index];
}

int Nvector::operator[](size_t index) const
{
	if (index >= size)
		throw "Invalid index";

	return data[index];
}

size_t Nvector::operator~() const
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const Nvector& v)
{
	os << "[ ";
	for (int i = 0; i < v.size; i++)
		os << v[i] << " ";
	os << " ]";

	return os;
}

std::istream& operator>>(std::istream& is, Nvector& v)
{
	for (int i = 0; i < v.size; i++)
		is >> v[i];

	return is;
}

bool operator||(const Nvector& lhs, const Nvector& rhs)
{
	if (~lhs != ~rhs)
		return false;

	double coef = (double)lhs[0] / rhs[0];

	double eps = 0.01;

	for (int i = 1; i < ~lhs; i++)
	{
		double currCoef = (double)lhs[i] / rhs[i];

		if (abs(currCoef - coef) > eps)
			return false;
	}
	return true;
}

Nvector& Nvector::operator*=(size_t scalar)
{
	for (int i = 0; i < size; i++)
		data[i] *= scalar;

	return *this;
}

const Nvector operator*(const Nvector& lhs, size_t scalar)
{
	Nvector copy(lhs);
	copy *= scalar;
	return copy;
}
const Nvector operator*(size_t scalar, const Nvector& lhs)
{
	return lhs * scalar;
}
size_t operator%(const Nvector& lhs, const Nvector& rhs)
{
	if (~lhs != ~rhs)
		throw "The vectors should have the same size!";

	size_t res = 0;
	for (int i = 0; ~lhs; i++)
		res += lhs[i] * rhs[i];

	return res;
}

size_t operator|=(const Nvector& lhs, const Nvector& rhs)
{
	return  lhs % rhs == 0; //the size check is done by %
}
