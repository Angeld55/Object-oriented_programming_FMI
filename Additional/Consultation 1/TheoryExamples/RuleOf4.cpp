#include <iostream>

struct A {
	A() {
		std::cout << "A constructor" << std::endl;
	}

	A(const A& other) {
		std::cout << "A copy-constructor" << std::endl;
	}

	A& operator=(const A& other) {
		std::cout << "A operator=" << std::endl;
		return *this;
	}

	~A() {
		std::cout << "A destructor" << std::endl;
	}
};

struct B {
	B() {
		std::cout << "B constructor" << std::endl;
	}

	B(const B& other) {
		std::cout << "B copy-constructor" << std::endl;
	}

	B& operator=(const B& other) {
		std::cout << "B operator=" << std::endl;
		return *this;
	}

	~B() {
		std::cout << "B destructor" << std::endl;
	}
};

struct C {
	A a;
	B b;

	C() {
		std::cout << "C constructor" << std::endl;
	}

	// you have to explicitly call a and b copy constr
	// otherwise the default constructors will be called
	C(const C& other) : a(other.a), b(other.b) {
		std::cout << "C copy-constructor" << std::endl;
	}

	// you have to explicitly call a and b operator=
	// otherwise nothing will be called
	C& operator=(const C& other) {
		a = other.a;
		b = other.b;
		std::cout << "C operator=" << std::endl;
		return *this;
	}

	~C() {
		std::cout << "C destructor" << std::endl;
	}
};

int main() {
	C c2, c3;
	C c1 = c2;
	c2 = c3;
}