#include "Queue.hpp"


int main()
{
	Queue<int> q;
	q.Enqueue(3);
	q.Dequeue();
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(6);
	cout<<q.Dequeue();

	cout << q.Dequeue();
	cout << q.Dequeue();
	cout << q.Dequeue();
	cout << q.Dequeue();
	cout << q.Dequeue();
	return 0;
}
