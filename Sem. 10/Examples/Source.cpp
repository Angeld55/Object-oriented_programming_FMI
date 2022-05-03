#include <iostream>
#include "MyString/MyString.h"
#include "Queue.hpp"
int main()
{
	{
		MyQueue<size_t> q;

		q.push(3);
		q.push(10);

		std::cout << q.peek() << std::endl;
		q.pop();

		std::cout << q.peek() << std::endl;
		q.pop();

	}
	{
		MyQueue<MyString> q;

		MyString name = "Ivan";

		q.push(std::move(name)); //so it could call push(MyString&&)

		MyString name2 = "Petur";
		q.push(name2); //push(const MyString&)

		q.push("Alex");//push(MyString&&)

		std::cout << q.peek() << std::endl;
		q.pop();

		std::cout << q.peek() << std::endl;
		q.pop();

		std::cout << q.peek() << std::endl;
		q.pop();
	}
}
