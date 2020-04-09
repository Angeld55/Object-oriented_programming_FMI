#include "TestClass.h"


TestClass::TestClass() : TestClass(0, 0, "Unknown")
{

}
TestClass::TestClass(int a, int b, const char* str)
{
	this->a = a;
	this->b = b;
	name = new char[strlen(str) + 1];
	strcpy(name, str);
}
TestClass::TestClass(const TestClass& other)
{
	CopyFrom(other);
	//name = other.name  NO! only the pointer will be copied.
}

TestClass& TestClass::operator=(const TestClass& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this; // this   TestClass*
}
TestClass::~TestClass()
{
	Free();
}
void TestClass::CopyFrom(const TestClass& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	a = other.a;
	b = other.b;
}
void TestClass::Free()
{
	delete[] name;
	a = b = 0;
}
