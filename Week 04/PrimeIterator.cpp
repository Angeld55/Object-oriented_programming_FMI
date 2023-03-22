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

	void goToNext()
	{
		//???
		while (!isPrime(++_value)) {}
	}
	void goToPrev()
	{
		if (_value == 2)
			return;
		while (!isPrime(--_value)) {}
	}

};
int main()
{

	for (PrimeIterator i(2); i.getValue() < 100; i.goToNext())
		std::cout << i.getValue() << std::endl;
}
