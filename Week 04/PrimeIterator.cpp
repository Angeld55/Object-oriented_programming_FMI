#include <iostream>

using namespace std;

class PrimeIterator
{
	unsigned _value;

	bool isPrime(size_t n)
	{
		if (n < 2)
			return false;
		double sqrtN = sqrt(n);
		for (unsigned i = 2; i <= sqrtN; i++)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
public:
	PrimeIterator(unsigned value)
	{
		setValue(value);
	}
	PrimeIterator() : PrimeIterator(2)
	{}

	size_t getValue() const
	{
		return _value;
	}
	void setValue(size_t value)
	{
		if (isPrime(value))
			_value = value;
		else
			_value = 2;
	}

	PrimeIterator& goToNext()
	{
		//todo: calc upper bound
		while (!isPrime(++_value)) {}
		return *this;
	}
	PrimeIterator& goToPrev()
	{
		if (_value != 2)
		{
			while (!isPrime(--_value)) {}
		}
		return *this;
	}

};
int main()
{

	for (PrimeIterator i(2); i.getValue() < 100; i.goToNext().goToNext()) //step is two
		std::cout << i.getValue() << std::endl;
}
