# Композиция на обекти. Масиви от обекти. Шаблони.
## Композиция
Композиция – класове като елементи на други класове (влагане на класове) Един клас може да включва в себе си обекти от други класове като член-данни. Когато обект от даден клас се дефинира, автоматично се извиква неговият конструктор. Ако класът съдържа член-данни, в неговия конструктор трябва да се укаже кои конструктори на член-данните да се извикват.
#### Пример 1
```c++
class A
{
 .
 .
 .
}
class B
{
	 int n;
	 A obj;
}
 ```
В тази ситуация се извикват **default-ните те конструктори на n и obj**.
#### Пример 2
```c++
class A
{
	A(int a, int b)
 .
 .
 .
}
class B
{
	B() : A(1, 2)
	{}
	
	int n;
	A obj;
}
 ```
Тук A няма default-ен конструктор. Това означава, че в конструктора на B трябва да се извика **експлицитно** някой от неговите конструктори
### Композиция на обекти с динамична памет
Когато имаме композиция и в главния клас има динамично заделяне на памет, то трябва в реализацията на копи-конструктора и оператор=  **експлицитно** да се извикват копи-конструкторите и оператора = за всички член-данни (композирани обекти). 
```c++
class B;

class A
{
	void copyFrom(const A& other)
	{
		arr = new int[other.size];
		for (int i = 0; i < other.size; i++)
			arr[i] = other.arr[i];
		size = other.size;
	}
	void free()
	{
		delete[] arr;
	}

public:
	B nestedObject;
	int* arr; //dynamic array
	size_t size; 
  
	A(int n) : size(n)
	{
		arr = new int[n];
	}
	A(const A& other) : nestedObject(other.objTest), size(other.size)
	{
		copyFrom(other);
	}
	A& operator=(const A& other)
	{
		nestedObject= other.nestedObject;
		size = other.size;

		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	~A()
	{
		free();
	}
};
 ```
 **ВАЖНО**: Деструкторите на член-данните **НЕ** трябва да се извикват експлицитно в деструктора на класа.


## Шаблони
Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас
```c++
#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    int a = 4;
    int b = 9;
    cout << sum<int>(a, b) << endl;

    double c = 3.14;
    double d = 4.5;
    cout << sum<double>(c,d) << endl;
	
    return 0;
}
```
Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

**Задача 1:**
Релизирайте структурата от данни опашка. Опашката трябва да работи с **произволни типове**. След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат премахнати всички елементи преди него в реда, в който са добавени.

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
  **Задача 2:**
 Създайте **шаблонна** опашка с k приоритета. При взимане на елемент от опашката трябва да се връща най-отдавна добавения елемент от тези с най-висок приоритет.
 
  ```c++
int main()
{
	kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.
	
	q.enqueue('A',0): //adds A with lowest priority: 0
	q.enqueue('B',3);
	q.enqueue('C',2);
	q.enqueue('D',2);
	q.enqueue('E',1);
	
	//q.enqueue('F', 5); //error! No such priority!
	
	q.dequeue(); // B
	q.dequeue(); // C
	q.dequeue(); // D
	q.dequeue(); // E
	q.dequeue(); // A
}
 ```
