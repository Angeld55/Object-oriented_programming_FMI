#include "Interval.h"
#include <algorithm>
#include <cmath>

void Interval::setA(int a)
{
	if (a > _b)
		a = _b;
	_a = a;
}
void Interval::setB(int b)
{
	if (b < _a)
		b = _a;
	_b = b;
}

int Interval::getA() const
{
	return _a;
}
int Interval::getB() const
{
	return _b;
}

Interval::Interval() : Interval(0, 0)
{}

Interval::Interval(int a, int b) 
{
	setA(a);
	setB(b);
}

bool Interval::isInInterval(int x) const
{
	return _a <= x && x <= _b;
}
namespace
{
	bool isPrime(int n)
	{
		if (n < 2)
			return false;

		double temp = sqrt(n);

		for (int i = 2; i <= temp; i++)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}

	int reverse(int n)
	{
		int reversed = 0;

		while (n != 0)
		{
			reversed = reversed * 10 + n % 10;
			n /= 10;
		}
		return reversed;
	}

	bool isPalindrome(int n)
	{
		return n == reverse(n);
	}
}
unsigned Interval::getCountCondition(bool (*predicate)(int)) const
{
	unsigned count = 0;
	for (int i = _a; i <= _b; i++)
	{
		if (predicate(i))
			count++;
	}
	return count;
}

unsigned Interval::getPrimesCount() const
{
	return getCountCondition(isPrime);
}

unsigned Interval::getPalindromesCount() const
{
	return getCountCondition(isPalindrome);
}

bool Interval::isSubinterval(const Interval& other) const
{
	return  _a >= other._a && _b <= other._b;
}

Interval intersectIntervals(const Interval& lhs, const Interval& rhs)
{
	int newA = std::max(lhs.getA(), rhs.getA());
	int newB = std::min(lhs.getB(), rhs.getB());

	if (newA > newB)
		throw "Error";

	return Interval(newA, newB);
}