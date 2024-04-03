#include "NVector.h"

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

Nvector operator+(const Nvector& lhs, const Nvector& rhs)
{
	Nvector lhsCopy(lhs);
	lhsCopy += rhs;

	return lhsCopy;
}

Nvector operator-(const Nvector& lhs, const Nvector& rhs)
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
	if (~lhs != ~rhs) {
		throw "The vectors should have the same size!";
	}

    double ratio = 0.0;
    bool ratioSet = false;

    for (size_t i = 0; i < lhs.size(); ++i) 
    {
        // Skip if both components are zero
        if (lhs[i] == 0 && rhs[i] == 0) 
        {
            continue;
        }
        // If one component is zero but the other is not, vectors are not parallel
        if (lhs[i] == 0 || rhs[i] == 0) 
        {
            return false;
        }
        
        // Calculate the ratio of the current components
        double currentRatio = lhs[i] / rhs[i];
        // If the ratio is not set, set it. Otherwise, compare it with the current ratio
        if (!ratioSet) 
        {
            ratio = currentRatio;
            ratioSet = true;
        } 
        else if (std::abs(ratio - currentRatio) > 1e-6) 
        { // Use a small epsilon for floating point comparison
            // If the ratios are different, vectors are not parallel
            return false;
        }
    }
    return true;
}

Nvector& Nvector::operator*=(size_t scalar)
{
	for (int i = 0; i < size; i++)
		data[i] *= scalar;

	return *this;
}

Nvector operator*(const Nvector& lhs, size_t scalar)
{
	Nvector copy(lhs);
	copy *= scalar;
	return copy;
}
Nvector operator*(size_t scalar, const Nvector& lhs)
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

bool operator|=(const Nvector& lhs, const Nvector& rhs)
{
	return  lhs % rhs == 0; //the size check is done by %
}

void Nvector::print() const
{
	std::cout << "[ ";
	for (int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << " ]";
}
