#include <iostream>
#include "Queue.hpp"

int main()
{
	MyQueue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);


	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();

	q.push(9);
	q.push(10);

	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();

	std::cout << "Is Empty: " << q.isEmpty() << std::endl;


}