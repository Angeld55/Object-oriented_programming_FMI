#include <iostream>
#include <algorithm>
#include "Interval.h"

bool isPrime(int n)
{
	double temp = sqrt(n);
	for (int i = 2; i <= temp; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isPalindorme(int n)
{
	int reversed = 0;

	while (n != 0)
	{
		int lastDigit = n % 10;
		(reversed *= 10) += lastDigit;
		n /= 10;
	}
	return n == reversed;
}
bool containsOnlyDistinctNumbers(int n)
{
	bool digits[10];
	for (int i = 0; i < 10; i++)
		digits[i] = false;

	while (n != 0)
	{
		int lastDigit = n % 10;
		if (digits[lastDigit])
			return false;
		digits[n % 10] = true;
		n /= 10;
	}
	return true;
}

size_t Interval::countNumbersInIntervalCondition(bool(*pred)(int)) const
{
	size_t count = 0;
	for (int i = a; i <= b; i++)
	{
		if (pred(i))
			count++;
	}
	return count;
}

Interval::Interval() : Interval(0, 0) {}

Interval::Interval(int a, int b)
{
	if (a > b)
		a = b = 0;

	this->a = a;
	this->b = b;
}

int Interval::getA() const
{
	return a;
}

int Interval::getB() const
{
	return b;
}
void Interval::setA(int a)
{
	if (a > b)
		return;
	this->a = a;
}

void Interval::setB(int b)
{
	if (b < a)
		return;
	this->b = b;
}

size_t Interval::getLength() const
{
	return b - a + 1;
}

bool Interval::isMemberOfInterval(int x) const
{
	return (a <= x && x <= b);
}

size_t Interval::calcPrimeNumbersInTheInterval() const
{
	return countNumbersInIntervalCondition(isPrime);
}

size_t Interval::calcPalindromicNumbersInTheInterval() const
{
	return countNumbersInIntervalCondition(isPalindorme);
}

size_t Interval::calcDiffrentDigitNumbersInTheInverval() const
{
	return countNumbersInIntervalCondition(containsOnlyDistinctNumbers);
}

bool Interval::areStartAndEndPowersOfTwo() const
{
	return (a == 0 || (a & a - 1) == 0) && (b == 0 || (b & b - 1) == 0);
}

Interval Interval::intersect(const Interval& other) const
{
	if (b < other.getA() || a > other.getB())
		return Interval(0, 0);

	int newA = std::max(a, other.getA());
	int newB = std::min(b, other.getB());

	return Interval(newA, newB);
}
bool Interval::isSuperInterval(const Interval& other) const
{
	return a <= other.getA() && b >= other.getB();
}