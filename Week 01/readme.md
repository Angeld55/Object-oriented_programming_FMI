#  **Преговор на указатели, референции и динамична памет. Увод в ООП. Обекти. Структури и обединения**

- [Преговор. Указатели, референции, динамична памет.](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#%D0%BF%D1%80%D0%B5%D0%B3%D0%BE%D0%B2%D0%BE%D1%80-%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B8-%D1%80%D0%B5%D1%84%D0%B5%D1%80%D0%B5%D0%BD%D1%86%D0%B8%D0%B8-%D0%B4%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D1%87%D0%BD%D0%B0-%D0%BF%D0%B0%D0%BC%D0%B5%D1%82)
- [Обектно-ориентирано програмиране](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#%D0%BE%D0%B1%D0%B5%D0%BA%D1%82%D0%BD%D0%BE-%D0%BE%D1%80%D0%B8%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%B0%D0%BD%D0%BE-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%B8%D1%80%D0%B0%D0%BD%D0%B5)
- [Структури](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B8)
- [Представяне в паметта и подравняване](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#%D0%BF%D1%80%D0%B5%D0%B4%D1%81%D1%82%D0%B0%D0%B2%D1%8F%D0%BD%D0%B5-%D0%B2-%D0%BF%D0%B0%D0%BC%D0%B5%D1%82%D1%82%D0%B0-%D0%B8-%D0%BF%D0%BE%D0%B4%D1%80%D0%B0%D0%B2%D0%BD%D1%8F%D0%B2%D0%B0%D0%BD%D0%B5)
- [Обединения](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#%D0%BE%D0%B1%D0%B5%D0%B4%D0%B8%D0%BD%D0%B5%D0%BD%D0%B8%D1%8F)
- [Енумерации](https://github.com/Angeld55/Object-oriented_programming_FMI/tree/master/Week%2001#%D0%B5%D0%BD%D1%83%D0%BC%D0%B5%D1%80%D0%B0%D1%86%D0%B8%D0%B8-enums)
- [Namespaces](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#namespaces)
- [Задачи](https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2001/README.md#%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8)

##  **Преговор. Указатели, референции, динамична памет.**
<img style="object-fit:contain;" align="right" width="450" height="600" src="https://study.com/cimages/multimages/16/1724cf83-a8ad-4ad5-aeca-0311114a819c_memory_alloc_cpp.png">

Паметта, която можем да използваме в **C++** има 4 основни типа:
<br />

*	**Глобална (Статична)**: в тази памет се записват статичните/глобалните променливи.
*	**Стекова (stack)**: тя съдържа "локалните" променливи, т.е. онези, които са дефинирани в телата на функции и са същевременно нестатични.
	  * Заделя се в момента на дефиниция на променливите и се освобождава в момента на изход от scope-a, в която е дефинирана;
	  * Последно заделената памет се освобождава първа (First in Last out);
	  * Количеството заделена памет е определена по време на компилация;
	  * Ние нямаме контрол над управлението над паметта
*	**Динамична (heap)**: е "свободната" част от паметта, която се използва (<em>динамично</em>) в хода на програмата. 
	* Заделя се и се освобождава по всяко време на изпълнение на програмата;
	* Областта за динамична памет е набор от свободни блокове памет;
	* Програмата може да заяви блок с произволна големина;
	* Имаме контрол над управлението на паметта;	  
*	**Program Code**: памет, в която се пази нашият компилиран код
	* Може да се достъпва с function pointer-и

### **Създаване на променливи (в статичната и динамичната памет)**
 ```c++
int main()
{
	int a = 10; // int in the stack
	int* ptr = new int(30); // int in the dyniamic memory
                            // we use a pointer on the stack to point to the int

	// print the value of the int in the stack and the one in the heap
	std::cout << "First number: " << a << " " << " second number: " << (*ptr) << std::endl;
	
	// ptr holds an address in the dynamic memory where the int is placed
	std::cout << "Address of second number" << ptr << std::endl;
	
	delete ptr; // delete the int in the stack to prevent memory leak
	
	ptr = &a;   // redirect the pointer to int in the stack
	std::cout << "Address of first number" << ptr << std::endl; // now ptr holds the address that is in the stack
	
	int& b = a; // creates int which data is on the address of a => they share the same memory
	b = 30;
	
	std::cout << "First number" << a << std::endl // 30
}
 ```

### **Подаване на параметри във функция**

#### **Подаване по копие.**

 ```c++
#include <iostream>

void f(int a)
{
	a++; // a++ will increment the value of the copy
}

int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //10
}
 ```
#### **Подаване по референция.**

 ```c++
 #include <iostream>
 
void f(int& a)
{
	a++; // a++ will increment the actual value of the passed variable
}

int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //11
}
 ```
#### **Подаване по указател.**

 ```c++
#include <iostream>

void f(int* a)
{
	(*a)++; // a++ will increment the value at the address where the pointer points at
}

int main()
{
	int a = 10;
	f(&a); // &a gives us the address of a which can be assigned to a pointer variable
	std::cout << a << std::endl; //11
}
 ```
 
## **Обектно-ориентирано програмиране**
Програмна парадигма -  представлява фундаменталния стил на програмиране. <br />
![Paradigms](img/Paradigms.png)
Обектно-ориентирано програмиране е **програмна парадигма**, при която една програмна система се моделира като набор от обекти, които взаимодействат помежду си, за разлика от традиционното виждане, в което една програма е списък от инструкции, които компютърът изпълнява. Всеки обект е способен да получава съобщения, обработва данни и праща съобщения на други обекти.

### **Принципи:**
- Абстракция
  - процесът на скриване на ненужни подробности от потребителя
- Капсулация
  - един обект трябва да предоставя на ползващия го само пряко необходимите му средства за управление.
- Наследяване
  - позволява да бъдат дефинирани и създавани обекти, които са специализирани варианти на вече съществуващи обекти.
  - класът наследник взема всички свойства и методи на класа-родител
- Полиморфизъм
  - представлява свойството на обектите от един и същи тип да имат един и същи интерфейс, но с различна реализация на този интерфейс.

**Техническият дълг** е концепция в програмирането, която отразява допълнителната разработка, която възниква, когато се използва лесен за изпълнение код в краткосрочен план, вместо да се прилага най-доброто цялостно решение. <br/>

##  [**Структури**](https://en.cppreference.com/w/c/language/struct)

Структурите в C++ се използват за групиране на елементи. Елементите, наричани още членове, могат да бъдат от различен тип и с различна дължина.

```c++
struct Box
{
	double height;
	double width;
	double length;
	// double height, width, length; is also possible
}
 ```

###  **Деклариране на обекти от новия тип**
 ```c++
Box b; // default values to height and width and length

Box b2 = {3, 4, 3.4} // height = 3, width = 3, length = 3.4;

Box b3;
b3.height = 13;
b3.width = 14;
b3.lenght = 20;
 ```
	
#### **Подаване във функции**
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
#### **Създаване на динамични обекти**
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

	// different types of assigning a value to a property when you have a pointer
	(*boxPtr).height = 3;
	(*boxPtr).width = 1;
	boxPtr->length = 4;
	
	std::cout << calculcateVolume(*boxPtr) << std::endl;
	
	delete boxPtr;
}
```

#### **Влагане на обекти**
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

#### **Масиви от обекти**
 ```c++
struct Box
{
	double height;
	double width;
	double length;
};

int main()
{
	Box arr1[30]; // 30 boxes
	Box* arr2 = new Box[20] // 20 boxes in dynamic mem.
	
	std::cout << arr1[0].height << " " << arr2[3].width << std::endl;

	delete[] arr2;
}
