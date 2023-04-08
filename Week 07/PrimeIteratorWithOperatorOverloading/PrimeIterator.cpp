#include <iostream>
#include <fstream>
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

	PrimeIterator& operator++()
	{
		return goToNext();
	}

	PrimeIterator operator++(int)
	{
		PrimeIterator oldCopy = *this;
		goToNext();
		return oldCopy;
	}

	PrimeIterator& operator--()
	{
		return goToPrev();
	}

	PrimeIterator operator--(int)
	{
		PrimeIterator oldCopy = *this;
		goToPrev();
		return oldCopy;
	}

	unsigned operator*() const
	{
		return _value;
	}
};


bool operator==(const PrimeIterator & lhs, const PrimeIterator & rhs)
{
	return lhs.getValue() == rhs.getValue();
}

bool operator!=(const PrimeIterator& lhs, const PrimeIterator& rhs)
{
	return lhs.getValue() != rhs.getValue();
}

int main()
{ 
	for (PrimeIterator it(2); *it < 100; it++)
		std::cout << *it << " ";

}
