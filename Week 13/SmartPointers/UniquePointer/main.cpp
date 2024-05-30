#include <memory>
#include <iostream>

struct A
{
	A(int a) : x(a)
	{
		std::cout << "A(int)" << std::endl;
	}
	int x;
	~A()
	{
		std::cout << "~A()" << std::endl;

	}
};
int main()
{

	std::unique_ptr<A> ptr(new A(1));
	std::cout << ptr->x << std::endl;
}