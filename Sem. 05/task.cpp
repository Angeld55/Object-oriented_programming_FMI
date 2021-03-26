#include <iostream>
#include <algorithm>
#include <fstream>
#include <functional>

using namespace std;

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
struct Interval
{
private:
	int a;
	int b;

	size_t countNumbersInIntervalCondition(bool(*pred)(int)) const
	{
		size_t count = 0;
		for (int i = a; i <= b; i++)
		{
			if (pred(i))
				count++;
		}
		return count;
	}
public:
	Interval() : Interval(0, 0) {}

	Interval(int a, int b)
	{
		if (a > b)
			a = b = 0;

		this->a = a;
		this->b = b;
	}
	int getA() const
	{
		return a;
	}

	int getB() const 
	{
		return b;
	}
	void setA(int a)
	{
		if (a > b)
			return;
		this->a = a;
	}

	void setB(int b)
	{
		if (b < a)
			return;
		this->b = b;
	}

	size_t getLength() const
	{
		return b - a + 1;
	}

	bool isMemberOfInterval(int x) const
	{
		return (a <= x && x <= b);
	}

	size_t calcPrimeNumbersInTheInterval() const
	{
		return countNumbersInIntervalCondition(isPrime);
	}

	size_t calcPalindromicNumbersInTheInterval() const
	{
		return countNumbersInIntervalCondition(isPalindorme);
	}

	size_t calcDiffrentDigitNumbersInTheInverval() const
	{
		return countNumbersInIntervalCondition(containsOnlyDistinctNumbers);
	}

	bool areStartAndEndPowersOfTwo() const
	{
		return (a == 0 || (a & a - 1) == 0) && (b == 0 ||(b & b - 1) == 0);
	}

	Interval intersect(const Interval& other) const
	{
		if (b < other.getA() || a > other.getB())
			return Interval(0, 0);
		
		int newA = std::max(a, other.getA());
		int newB = std::min(b, other.getB());

		return Interval(newA, newB);
	}
	bool isSubInterval(const Interval& other) const
	{
		return a <= other.getA() && b >= other.getB();
	}
};

int main()
{
	Interval i(1, 11);

	cout << i.calcDiffrentDigitNumbersInTheInverval() <<endl;

	cout << i.getLength()<<endl;
	

}
 
