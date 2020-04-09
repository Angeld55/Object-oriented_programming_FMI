#include <iostream>
class TestClass
{
private:

	void CopyFrom(const TestClass& other);
	void Free();
	int a;
	int b;
	char* name;

public:


	TestClass(int a, int b, const char* str);
	
	// big4
	TestClass();
	TestClass(const TestClass& other);
	TestClass& operator=(const TestClass& other);
	~TestClass();

	void Print() const;

};
