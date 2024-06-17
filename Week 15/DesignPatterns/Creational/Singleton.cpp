#include <iostream>

class SingletonClass {
private:
	SingletonClass() {
		std::cout << "SingletonClass was created" << std::endl;
	}

	~SingletonClass() {
		std::cout << "SingletonClass was destroyed" << std::endl;
	}
public:
	static SingletonClass& getInstance() {
		static SingletonClass instance;
		return instance;
	}

	SingletonClass(const SingletonClass& other) = delete;
	SingletonClass& operator=(const SingletonClass& other) = delete;

	void doStuff() {
		std::cout << this << std::endl;
	}
};

int main() {
	{
		std::cout << "hello";
		SingletonClass& s1 = SingletonClass::getInstance();
	}
	SingletonClass& s2 = SingletonClass::getInstance();
	s2.doStuff();
	SingletonClass& s3 = SingletonClass::getInstance();
	s3.doStuff();
	SingletonClass& s4 = SingletonClass::getInstance();
}
