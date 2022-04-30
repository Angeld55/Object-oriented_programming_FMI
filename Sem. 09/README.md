


##  Масиви от указатели към обекти. Изключения. Move семантики.
Масиви от указатели към обекти.

 ```c++
class SomeCollection
{
	A** data;
	//other things
};
 ```
![enter image description here](https://i.ibb.co/YDCL2nr/pointer-Of-Pointers.png)
#####  Какви са ползите:

 - Бързо разместване на обектите в колецкията - не се изисква да се копират. Само разместваме указателите
 - Не се изисква същестуването на деф. контруктор на A.
 - Възможно е да имаме "празна клетка", като се възползваме от възможната nullptr стойнот.


###  Изключения
![enter image description here](https://i.ibb.co/hDMRzMB/df-drawio-1.png)

 - Защо е хубаво да извикваме .close() на потоците екпслицитно ?

###  Move сменатики

#### Подаване на стойност по референция
```c++
#include <iostream>
using namespace std;

void f(int& n)
{
	cout << n << endl;
}
int main()
{
	int number = 10;
	f(number); // OK!
	f(3);      // Error!
}
 ```
"Висящата" константа 3 **няма адрес в паметта**. За това подаването и като параметър на функцията f ще доведе до компилационна грешка. 

**&&** - за стойности без адрес в паметта
```c++
#include<iostream>
using namespace std;

void f(int& n)
{
	cout << n << endl;
}
int main()
{
	int number = 10;
	f(number); // OK!
	f(3);      // Error!
}
 ```

#### Пример за използването на &&
```c++
#include<iostream>
using namespace std;

void f(int&& n)
{
	cout << n << endl;
}
int main()
{
	int number = 10;
	f(number); // Error!
	f(3);      // OK!
}
 ```
Тук грешката възниква при подаването на променлива, която **има адрес в паметта.**
#### lvalue и rvalue

 - **lvalue** - обект, който заема някакво конкретно място в паметта. (стойността в паметта може да се модифицира)
 - **rvalue** - обект, който не е  *lvalue* .


#### Излишни копия?
Да разгледаме следният програмен фрагмент:
 
```c++
#include<iostream>
#include<iostream>
#include "Person.h"
using namespace std;

Person createPerson(const char* name, int age)
{
	Person p(name, age);

	return p;
}

int main()
{
	Person p2("Petur",18);
	p2 = createPerson("Ivan", 23);
}
 ```
Тук се изпълняват следните функции на Person:

 1. Конструктор на Person (за p2)
 2. Конструктор за Person (на p).
 3. Копиращ конструктор (за *return p*)
 4. Деструктор (в края на функцията *createPerson*)
 5. Оператор = (за *p2 = create...* )   
 6. Деструктор (в края на функцията *main*)

Проблемът тук е, че правим излишни копия.  Обектът създаден в *createPerson* **се копира два пъти докато се присвои** на p2.
#### Move конструктор и move оператор =.
За да избегнем излишните копия, може да "преместим" данните на обектът, който се създава във функцията, в данните на p2.
```c++

//Move constructor
Person::Person(Person&& rhs)
{
	name = rhs.name;
	age = rhs.age;

	rhs.name = nullptr;
}

//Move operator=
Person& Person::operator=(Person&& rhs)
{
	if (this != &rhs)
	{
		free();

		name = rhs.name;
		rhs.name = nullptr;
	}
	return *this;
}
 ```
 
 Важно е да се обърне внимание, че тук данните **не се копират**, а се **местят**. Т.е приемаме, че rhs **няма да се използва след изпълнението на функцията.**
 Сега при изпълнението на първоначално разгледания код:
  1. Конструктор на Person (за p2)
 2. Конструктор за Person (на p).
 3. **Move конструктор** (за *return p*)
 4. Деструктор (в края на функцията *createPerson*)
 5. **Move oператор =** (за *p2 = create...* )   
 6. Деструктор (в края на функцията *main*)
 

Т.е тук си спестихме 2 копия за динамичната памет в Person.
