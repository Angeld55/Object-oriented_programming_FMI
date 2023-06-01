#include <memory>
#include <iostream>

struct A
{
	A(int a)
	{
		std::cout << "A(int)" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;

	}
};
int main()
{
	
	std::unique_ptr<A> ptr(new A(1));

}
