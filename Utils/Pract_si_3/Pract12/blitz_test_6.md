## Blitz test 6

1. Какво ще се изведе на конзолата след изпълнението на задачата?
```c++
#include <iostream>

class A
{
public:
    virtual void f()
    {
        std::cout << "A";
    }
    virtual ~A() = default;
};

class B : public A
{
public:
    void f() override
    {
        std::cout << "B";
    }
};

class C : public B
{
public:
    void f() const
    {
        std::cout << "C";
    }
};

int main()
{
    A* ptr = new C();
    ptr->f();
}
```

2. Какво ще се изведе на конзолата след изпълнението на програмата?
```c++
#include <iostream>

class A
{

public:
    virtual void f() const
    {
        std::cout << "A";
    }
};

class B : public A
{
    int anotherNumber;
    char c;
public:
    void f() const override
    {
        std::cout << "B";
    }
    virtual void g() const {
        std::cout<<"B::g()";
    }
};
class C : public B {
    char c;
};

int main()
{
    std::cout << sizeof(A);
    std::cout << sizeof(B);
    std::cout << sizeof(C);
}
```

3. Какво ще се изведе на конзолата след изпълнението на програмата?

```c++
#include <iostream>

class Base {
	int a;
public:
	Base() {
		std::cout << "Base()\n";
	}
	virtual void f() const {
		std::cout << "Base::f\n";
	}
	~Base() {
		std::cout << "~Base()\n";
	}

};

class Der1 : public Base {
	int b;
public:
	Der1() {
		std::cout << "Der1()\n";
	}
	void f() const override {
		Base::f();
		std::cout << "Der1::f\n";
	}

	~Der1() {
		std::cout << "~Der1()\n";
	}
};

class Der2 : public Der1 {
	int c;
public:
	Der2() {
		std::cout << "Der2()\n";
	}

	~Der2() {
		std::cout << "~Der2()\n";
	}

};

int main() {
	Base* ptr = new Der2();
	ptr->f();
	delete ptr;
}
```

4. Напишете проста реализация на полиморфна йерархия, където в базовия клас има:

* чисто виртуална функция print(), която принти типа на съответния клас

Имате наследник Der2, който наследява Der1, който наследява Base

Напишете логика, чрез която по време на изпълнение на програмата да може да създаваме точно копие
на обект, без да се интересуваме от типа му.
