#include <iostream>

struct A
{
	virtual void f()
	{
		std::cout << "A::f()" << std::endl;
	}
	virtual void g()
	{
		std::cout << "A::f()" << std::endl;
	}
	void non_virtual_function()
	{
		std::cout << "A::non-virt()" << std::endl;
	}
};

struct B : public A
{
	void f()
	{
		std::cout << "B::f()" << std::endl;
	}
	void g()
	{
		std::cout << "B::f()" << std::endl;
	}
	void h()
	{
		std::cout << "B::f()" << std::endl;
	}
};

struct C : public B
{
	void f()
	{
		std::cout << "C::f()" << std::endl;
	}
	void non_virtual_function()
	{
		std::cout << "C::non_virtual_function()" << std::endl;
	}

};

struct D : public C
{
	void f()
	{
		std::cout << "C::f()" << std::endl;
	}
	void d()
	{
		std::cout << "D::h()" << std::endl;
	}
};




int main()
{
	A objA;
	B objB;
	C objC;
	D objD;

	A* ptrA = &objA;

	ptrA->f();
	ptrA->g();
	ptrA->non_virtual_function();

	A* ptrB = &objB;

	ptrB->f();
	ptrB->g();
	ptrB->non_virtual_function();
	
	B* ptrC = &objC;

	ptrC->f();
	ptrC->g();
	ptrC->non_virtual_function();

	C* ptrD = &objD;

	ptrD->f();
	ptrD->g();
	ptrD->non_virtual_function();


}
