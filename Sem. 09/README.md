**Пример**:
 ```c++
int main()
{
	quene<int> q;
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(10);

	cout << q.dequeue() << endl; //3
	cout << q.dequeue() << endl; //5
	cout << q.dequeue() << endl; //10

	cout << q.isEmpty() << endl; //1	
}
 ```
