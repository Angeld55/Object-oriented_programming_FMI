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

## Масиви от обекти
#### Статичен масив от обекти
 
```c++
class A;
int main()
{
	A arr[5]; //5 def. constr.
} //5 destr
 ```
Създава **статичен** масив с 5 обекта от тип A. На всеки от тях се е извикал конструктора по подразбиране.
Масивът ще се изтрие, когато приключи функцията.
#### Статичен масив от указатели към обекти
```c++
class A;
int main()
{
	A* arr[10]; //5 empty pointers.
	
	arr[0] = new A();
	arr[2] = new A();
	
	delete arr[0];
	delete arr[2];
}
 ```
Създава **статичен** масив с 5 указателя . Само на 2 от тези указатели присвояваме обекти, които са заделени в динамичната памет.
Масивът ще се изтрие, когато приключи функцията.
#### Динамичен масив от обекти
```c++
class A;
int main()
{
	A* arr = new A[5]; //5 def constr.
	delete[] arr; //5 destr
} 
 ```
Създава **динамичен** масив с 5 обекта от тип A. На всеки от тях се е извикал конструктора по подразбиране.
Масивът ще се изтрие (и ще се изтрият обектите), когато се извика delete[] върху него.

#### Динамичен масив от указатели към обекти
```c++
class A;
int main()
{
	A** arr = new A*[5]; //5 empty pointers.
	
	arr[0] = new A(); //def constr. 
	arr[2] = new A(); //def constr.
	
	delete arr[0]; //destr.
	delete arr[2]; //destr.
	
	delete[] arr;
}
 ```
 Създава **динамичен** масив с 5 указателя . Само на 2 от тези указатели присвояваме обекти, които са заделени в динамичната памет.
Масивът ще се изтрие (и ще се изтрият обектите), когато се извика delete[] върху него.


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
## Задачи

**Задача 1:**
Трябва да реализирате библиотека за работа с факултатитен курс. 
Курсът ще има преподаватели - лектор и асистенти - имената им се приемат като параметри.
Асистентите могат да са най-много 3.

**Пример**:
 ```c++
int main()
{
	OOPcourse p("Lecturer1", "Assistant1");
	
	p.addStudent("Ivan Petrov", 45123);
	p.addStudent("Aleksandur Mironov", 45123);
	p.addStudent("Stefan Popov", 45123);
	
	p.addGrade(45123, "HW1", 4, "Assistant1");
	p.addGrade(45222, "HW1", 6, "Lecturer1");
	p.addGrade(45222, "K1", 5, "Assistant1");
	
	p.getAverage("HW1"); // 4.5;
	
	p.removeStudent(45123);
      
    p.getAverageGradePerTask("HW1"); // 5;
	
	p.getAverageFromTeacher("Lecturer1"); //6
	
}
 ```
Функционални изисквания:
 - Всеки студент трябва да има най-много една оценка за дадено задание.
 - Записана оценка за дадено задание може да се променя, но не може да се изтрива!
 - Във всеки момент трябва да може да се види каква е средната оценка, която е написал лекторът или асистентът.
 - Студент може да има най-много 20 оценки.
 - Студентите имат имена с макс дължина 30 символа.
 
**Задача 2:**
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
 **Задача 3:**
 Релизирайте клас стринг, който ще се ползва за работа със символни низове. Стрингът трябва да има като минимум следния интерфейс:
 

 - Конструктор по подразбиране (по поразбиране ще е празният низ)
 - Конструктор, който приема константен указател към масив от символи. 
 - Член-функция, която приема друг стринг и връща дали е подстринг на текущия.
 - Член-функция, която приема цяло число k и връща подстринг на текущия, но започващ от k-ти символ
 - Член-функция, която приема две цели числа k и t и връща подстринг на текущия, но започващ от k-ти символ и завършващ на t-ти символ.
 - Предефиниран оператор [] за достъп до произволен символите.
- Предефиниран оператори + и += за конкатенация на стрингове.
- Предефиниран оператор *, който приема стринг и цяло число k и мултиплицира съдържаниято на стринга k пъти.
- Предефинирани оператори << и >>.

**Пример**:
 ```c++
int main()
{
	myString s1(); ""
	myString s2("Test");
	
	s1 = "pronto";	

	s2.contains(s1); //false
	
	myString s3 = s1 + s2; // prostoTest
	
	s3*=3; //prontoTestprontoTestprontoTest
	
	cin >> s3;
	cout << s3 <<endl;
}
 ```