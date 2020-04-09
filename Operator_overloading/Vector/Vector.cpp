#include "Vector.h"

Vector::Vector() :coordinates(nullptr), length(0)
{}
Vector::Vector(int len)
{
	coordinates = new int[len];
	for (int i = 0; i < len; i++)
		coordinates[i] = 0;
	length = len;
}
void Vector::CopyFrom(const Vector& other)
{
    coordinates = new int[other.length];
	for (int i = 0; i < other.GetLen(); i++)
		coordinates[i] = other.coordinates[i];
	length = other.length;
}
void Vector::Free()
{
	delete[] coordinates;
	length = 0;
}
Vector::Vector(const Vector& other)
{
	CopyFrom(other);
}
Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Vector::~Vector()
{
	Free();
}

int& Vector::operator[](int index)
{
	if (index < length)
		return coordinates[index];
	else
		throw 0;
}
void Vector::print()
{
	std::cout << '(';
	for (int i = 0; i < length; i++)
		std::cout << coordinates[i]<<" ";
	std::cout <<')' <<std::endl;
}

int Vector::GetLen() const
{
	return length;
}
int Vector::GetAtIndex(int index) const
{
	if (index<length)
		return coordinates[index];
	else
		return 0;
}
Vector& Vector::operator+=(const Vector& other)
{
	if (GetLen() != other.GetLen())
		throw "Invalid operation";
	for (int i = 0; i < other.length; i++)
		coordinates[i] += other.coordinates[i];
	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	if (GetLen() != other.GetLen())
		throw "Invalid operation";
	for (int i = 0; i < other.length; ++i)
		coordinates[i] -= other.coordinates[i];
	return *this;
}

Vector& Vector::operator*=(int scalar)
{
	for (int i = 0; i < length; i++)
		coordinates[i] *= scalar;
	return *this;
}
Vector operator+(const Vector& lhs,const Vector& rhs)
{
	Vector temp(lhs);
	temp += rhs;
	return temp;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
	Vector temp(lhs);
	temp -= rhs;
	return temp;
}

int operator%(const Vector& lhs, const Vector& rhs)
{
	int min = lhs.GetLen() < rhs.GetLen() ? lhs.GetLen() : rhs.GetLen();
	int result = 0;
	for (int i = 0; i < min; i++)
		result += lhs.GetAtIndex(i) * rhs.GetAtIndex(i);
	return result;
}
bool operator||(const Vector& lhs, const Vector& rhs)// a и b са перпендикулярни <-> a*K=b (K е константа).
{
	double coeff = lhs.GetAtIndex(0) / rhs.GetAtIndex(0);
	for (int i = 1; i < lhs.GetLen(); i++)
	{
		if (lhs.GetAtIndex(i) == 0 || rhs.GetAtIndex(i) == 0)
			continue;
		double Newfirst = lhs.GetAtIndex(i);
		double Newcoeff = Newfirst / rhs.GetAtIndex(i);
		if (abs(Newcoeff-coeff)>0.01)
			return false;
	}
	return true;
}
bool operator|=(const Vector& lhs, const Vector& rhs)
{
	return lhs%rhs == 0; //скаларното произведение на два успоредни вектора е 0.
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	for (int i = 0; i < v.GetLen(); ++i)
		os << v.GetAtIndex(i) << " ";
	return os;
}

std::istream& operator>>(std::istream& ifs, Vector& v)
{
	for (int i = 0; i < v.GetLen(); ++i)
		ifs >> v[i];
	return ifs;
}
