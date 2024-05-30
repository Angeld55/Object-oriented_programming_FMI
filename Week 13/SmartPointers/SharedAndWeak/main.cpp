#include <iostream>
#include "WeakPtr.hpp"


struct A
{
	A() {
		std::cout << "A()" << std::endl;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}

};
int main()
{
	WeakPtr<A> wp;
	{
		SharedPtr<A> pt(new A());
		wp = pt;

		std::cout << wp.expired() << std::endl;
	}

	std::cout << wp.expired() << std::endl;
}