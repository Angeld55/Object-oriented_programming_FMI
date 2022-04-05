# Голямата четворка (Rule of four)

 - Конструктор по подразбиране (конструктор без параметри)
 - Конструктор за копиране
 - Оператор =
 - Деструктор
 
Да разгледаме следната структура:
```c++
struct Test
{
	char str[20];
	A obj2;
	B obj3;
};
 ```
 Понеже функциите (от голямата четворка) не са дефинирани в структурата, то компилаторът ще създаде такива:
 ```c++
int main()
{
	Test currentObject; //default constructor
	 
	Test object2(currentObject); //copy constructor
	 
	currentObject = object2; //operator =

} //destructor (x2)
 ```
 Кодът се компилира успешно и функциите имат правилно поведение.
###  Как работят дефинираните от компилатора функции?
 Всяка една от тезу функции **извиква рекурсивно същите функции връху член-данните.**
 ####  Пример за конструктора по подразбиране:
 
![enter image description here](https://i.ibb.co/smKkDpJ/def-constr.png)
 
  ####  Пример за деструктора:
![enter image description here](https://i.ibb.co/qNHfSTL/def-constr.png)

 ####  Пример за копиращия конструктор:
![enter image description here](https://i.ibb.co/QmCh9z6/cc.png)
### Проблем при функциите, генерирани от компилатора:

Да разгледаме следния код:

 ```c++
struct Person
{
	PersonA(const char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}
private:

	char* name;
	int age;
};

int main()
{
	Person p1;
	Person p2(p1);
}

 ```
 Горното извикване на копиращия конструктор има **грешено поведение**:

![enter image description here](https://i.ibb.co/q5rfGBf/Capture.png)


Това е **shallow copy**. В p2 са се копирали стойностите на p1, което довежда до споделяне на една и съща динамична памет.
В тази ситуация ще трябва да се имплементират експлицитно **копиращия конструктор, оператора за присвояване и деструктора**, защото генерираните от компилатора не биха работили правилно.

**Правилното поведение** на копиращия конструктор е следното:

![enter image description here](https://i.ibb.co/XZq5rGT/33.png)

### Собствена имплементация на функциите за копиране и деструктора

 ```c++
struct Person
{
	Person(const char* name, int age) : name(nullptr), age(age)
	{
		setName(name);
		setAge(age);
	}

	Person(const Person& other)
	{	
		copyFrom(other); // копираме
	}

	Person& operator=(const Person& other)
	{
		if (this != &other)
		{
			free(); //трием
			copyFrom(other); //копираме
		}
		return *this;
	}
	~Person()
	{
		free(); //трием
	}
	
	.
	.
	.
	
	

};

 ```

При всички класове, които използват динамична памет, тези функции изглеждат по този начин. Разликите са в имплементациите на функциите **free** и **copyFrom**.


