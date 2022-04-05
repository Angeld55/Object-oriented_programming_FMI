# Разделна компилация. Абстракция. Копиращ конструктор и оператор=

## Разделна компилация.

![enter image description here](https://gamedevunboxed.com/wp-content/uploads/2019/08/image.png)

Една програма на С++ може да бъде разбита в множество файлове, които се **компилират независимо един от друг**, т.е. осъществява се **разделна компилация**. В резултат на компилацията се получават няколко **обектни файла** (файлове с разширение **.obj**). Изпълнимият код напрограмата (файл с разширение .ехе) се получава след свързване на обектните файлове (**Linking**).

За да се възполваме максимално от разделната компилация, разделяме класовете на **.h** и **.cpp** файлове. Навсякъде където ще работим с класа, ще включваме **само .h файла.** По този начин, ако променим реализацията на някоя от функциите на класа, ще се **прекомпилира само този файл**.

![enter image description here](https://i.ibb.co/N9RnMHv/sss.png)

## Копиращ конструктор и оператор =
Заедно с конструктора по подразбиране и деструктора във всеки клас се дефинират и следните член-функции:
 -  Копиращ конструктор - конструктор, който приема обект от същия клас и създава новият обект като негово копие.
 - Оператор= - функция/оператор, който приема  обект от същия клас и променя данните на съществуващ обект от същия клас (обектът от който извикваме функцията.

**Забележка:** Копиращият конструктор създава нов обект, а оператор= модифицира вече съществуващ такъв!

 ```c++

#include <iostream>

using namespace std;

struct Test 
{

	Test()
	{
	cout << "Default constructor" <<endl;
	}

	Test(const Test& other)
	{
	cout << "Copy constructor" <<endl;
	}

	Test& operator=(const Test& other)
	{
	cout << "operator=" <<endl;
	}

	~Test()
	{
	cout << "Destructor" <<endl;
	}
};

void f(Test object)
{
	//do Stuff
}


void g(Test& object)
{
	//do Stuff
}
int main()
{
    Test t; //Default constructor;
	
    Test t2(t)  // Copy constructor
    Test t3(t2) // Copy constructor	
    Test t2 = t3 // operator=
    Test t3 = t //  operator=
    
    Test newTest = t; //Copy constructor !!!!!!!
	
    f(t); // Copy constructor	
    g(t); // nothing. We are passing it as a reference. We are not copying it!
    
    Test* ptr = new Test();  // Default constructor // we create a new object in the dynamic memory. The destructor must be invoked explicitly  (with delete)
	
    delete ptr; // Destructor	
	 
} //Destructor Destructor Destructor Destructor

 ```
