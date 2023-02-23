
#  Преговор на указатели, референции и динамична памет. Увод в ООП. Обекти. Структури и обединения


###  Преговор. Указатели, референции, динамична памет.

#### Създаване на променливи (в статичната и динамичната памет)
 ```c++
int main()
{
	int a = 10;				// int in the stack
	int* ptr = new int(30); // int in the dyniamic memory (we use a pointer on the stack to point to the int)

	std::cout << "First number: " << a << " " << " second number: " << (*ptr) << std::endl;
	
	std::cout << "Address of second number" << ptr << std::endl;
	
	delete ptr; //!!! 
	
	ptr = &a;
	std::cout << "Address of first number" << ptr << std::endl;
	
	int& b = a; //another name for the variable
	b = 30;
	
	std::cout << "First number" << a << std::endl 

}
 ```
#### Подаване на параметри във функция

##### Подаване по копие.

 ```c++
#include <iostream>
void f(int a)
{
	a++;
}
int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //10
}
 ```
##### Подаване по референция.

 ```c++
 #include <iostream>
void f(int& a)
{
	a++; //a++ will increment the pointer
}
int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //11
}
 ```
##### Подаване по указател.

 ```c++
#include <iostream>
void f(int* a)
{
	(*a)++; //a++ will increment the pointer
}
int main()
{
	int a = 10;
	f(&a); //&a returns a pointer to a.
	std::cout << a << std::endl; //11
}
 ```
##  Структури

Структурите в C++ се използват за групиране на елементи. Елементите, наричани още членове, могат да бъдат от различен тип и с различна дължина.
 ```c++
struct Box
{
	double height;
	double width;
	double length;
}
 ```

###  Деклариране на обекти от новия тип
 ```c++
Box b; //default values to height and width ans lenght

Box b2 = {3, 4, 3.4} // height = 3, width = 3, length = 3.4;

Box b3;
b3.height = 13;
b3.width = 14;
b3.lenght = 20;
 ```
	
#### Подаване във функции
Ако няма да променяме обекта го подаваме по **константна референция.**
 ```c++
double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}
```
   Може и само по **референция**, но тогава може да се правят промени върху подадения аргумент. 
   
 ```c++
void readBox(Box& b)
{
    cin >> b.height >> b.width >> b.length;
}
 ```
Може и да го подаваме по **копие**.
 ```c++
Box revertBox(Box b)
{
    int temp = b.height;
    b.height = b.width;
    b.width = temp;

    return b;
}
```
#### Създаване на динамични обекти
 ```c++
#include <iostream>

struct Box
{
	double height;
	double width;
	double length;
};

double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}

int main()
{
	Box* boxPtr = new Box();

	(*boxPtr).height = 3;
	(*boxPtr).width = 1;
	boxPtr->length = 4;
	
	std::cout << calculcateVolume(*boxPtr) << std::endl;
	
	delete boxPtr;
}
```

#### Влагане на обекти
 ```c++
struct Box
{
	double height;
	double width;
	double length;
};


struct Warehouse
{
	char name[1024];
	Box b1;
	Box b2;
};
int main()
{
	Warehouse w = { "Ekont", { 1, 2, 3 }, { 4, 5, 3 } };

	std::cout << w.name;
}
```

#### Масиви от обекти
 ```c++
struct Box
{
	double height;
	double width;
	double length;
};

int main()
{
	Box arr1[30]; //30 boxes
	Box* arr2 = new Box[20] //20 boxes in dynamic mem.
	
	std::cout << arr1[0].height << " " << arr2[3].width << std::endl;

	delete[] arr2;
}
```

#### Размер на обекти. Увод в подравняването.
 ```c++
struct A
{
	bool b;
	int c;
};

int main()
{
	std::cout << sizeof(A) << std::endl; //8 (not 5)
}
```

![enter image description here](https://i.ibb.co/nsCKYLN/struct.png)
##  Обединения 
Обединенията са част от паметта, която се поделя при съхранение на две или повече променливи. Променливите, поделящи паметта могат да са от различни типове. Във всеки един момент обаче може да се ползва само една променлива от състава на обединението.

 ```c++
#include <iostream>

union A
{
	int a;
	char b;
	short c;
};


int main()
{
	A obj;

	obj.a = 32768;

	std::cout << obj.a << std::endl;
	std::cout << obj.b << std::endl;	
	std::cout << obj.c << std::endl;

}
```

![enter image description here](https://i.ibb.co/4m6m5Mg/union.png)

### Задачи

**Задача 1:** Въвежда се цяло число **N**  и после **N** тригъгълника в равнината, определени от 3 точки ( 6 координати).
Отпечатайте тригълниците **сортирани по лицата им.**


**Задача 2:** Резлизирайте структура Rational, която е за работа с рационални числа. Имплементирайте функции за събиране, изваждане, умножение и деление. Имплементирайте функция. Имеплементирайте функция, която приема истанция(обект) от новия тип и връща дали е валидно рационално число, както и функция, която връща дали е цяло число.
