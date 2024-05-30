#include <iostream>


template <class Func1Type, class Func2Type>
class FuncAverage
{
	Func1Type f1; //не позволявате контекст
	Func2Type f2;
	
public:
	FuncAverage(const Func1Type& f1, const Func2Type& f2) : f1(f1), f2(f2) {}
	double operator()(int x)
	{
		return (f1(x) + f2(x)) / 2.0;
	}
};

class FuncWithContext
{
	int a;
	int b; 
	int c;
public:
	int operator()(int x)
	{

	}
};
int main()
{
	FuncWithContext myFunc;

	FuncAverage<int(*)(int), FuncWithContext> f([](int x) {return x; },
				  myFunc);
	
	std::cout << f(10);
}