#include <iostream>

class Test {
private:
	int a;
	Test(bool a) {
		this->a = a;
	}

public:
	Test(int a) {
		setA(a);
	}

	int getA() const {
		return a;
	}

	void setA(int a) {
		this->a = a;
	}

	Test createConditionalDuplicate() const {
		return Test(a > 0);
	}
};

void func() {
	Test t(-5);
	Test t2 = t.createConditionalDuplicate();
	std::cout << t.getA() << std::endl;
	std::cout << t2.getA();
}

void func2(const Test& t) {
	t.getA();
	t.createConditionalDuplicate();
	//t.setA(); // error
}