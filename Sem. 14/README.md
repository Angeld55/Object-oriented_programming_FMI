# Преобразуване между типове, Factory pattern, Множествено наследяване. Диамантен проблем

## Множествено наследяване.
Множественото наследяване позволява на "детски" клас да наследява от повече от един родителски клас.
![enter image description here](https://d33wubrfki0l68.cloudfront.net/67512abb598d0aef77410deee207b42323b17f8e/70284/wp-content/uploads/2018/07/multiple-inheritance.png)

Копиращия конструктор и оператор= (независимо дали ги имплементираме ние) трябва да изглеждат така:
```c++
MyClass(const MyClass& other) : SuperClass1(other), SuperClass2(other), SuperClass3(other), SuperClass4(other)
{ 
	copyFrom(other); //copy only the MyClass stuff)
}

MyClass(const MyClass& other)
{
	if(this != &other)
	{
		SuperClass1::operator=(other);
		SuperClass2::operator=(other);
		SuperClass3::operator=(other);
		SuperClass4::operator=(other);
		free();
		copyFrom(other);
	}
}
 ```

## Диамантен проблем


![enter image description here](https://i.stack.imgur.com/MqMW0.png)

**Проблем**: Многократно наследяване на базов клас – нееднозначност при използване.
В класът **D** има две истанции на **A**. Искаме характеристиките на **А** да бъдат наследени само веднъж.

Преодоляването на голяма част от недостатъците на многократното наследяване на клас се осъществява чрез използване на т.н. виртуални основни класове.
Дават възможност за „поделяне“ на компонентите на основните класове.  Създава се само едно тяхно копие
Декларира се като в декларацията на производния клас заедно с името и атрибута за област на основния клас се укаже и ключовата дума virtual
```c++
class B : virtual A { ... }
class C : virtual A { ... }
 ```

Конструкторите с параметри на виртуални класове трябва да се извикват от конструкторите на **всички класове, които са техни наследници, а не само от конструкторите на преките им наследници.**

```c++
D::D(...) : B(...), C(...), A(...) {} //we call explicit the constructor of A
 ```

## Factory pattern
Използваме factory-фунцкия за създаване на обектите,.

## Преобразуване между типове

 - dynamic_cast<T>();
 - static_cast<T>();
 - const_cast<T>();
 - reintereted_cast<T>()
 - (T) - C-style cast
