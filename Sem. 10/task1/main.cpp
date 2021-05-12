#include <iostream>
#include "Queue.hpp"
using namespace std;



int main()
{
	Queue<char> q;

	q.enqueue('A');
	q.enqueue('B');
	q.enqueue('C');
	q.enqueue('D');
	cout << q.dequeue() << endl;
	q.enqueue('E');
	q.enqueue('F');
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
}