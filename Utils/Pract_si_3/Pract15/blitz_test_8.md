# Blitz test №8
**При всички задачи работим в Little-Endian x86 операционна система (4-байтови указатели)**

**Здача 1.** Дадена е следната йерархия. Начертайте как ще изглежда в паметта обект от тип E. (Трябва да се вижда ясно разположението на всеки родителски клас)

```c++
struct A
{
	int a;
};

struct B : virtual A
{
	int b;
};

struct C : virtual A
{
	int c;
};

struct D : A
{
	int d;
};

struct E : B, C, D
{
	int e;
};
```

**Здача 2.** Попълнете виртуалната таблица на A в следният случай:
![image](https://github.com/desiish/OOP_Pract_2023_2024/assets/115353472/345be363-e71e-4a5b-a2c8-1861c0eeb06b)

<img src=![image](https://github.com/desiish/OOP_Pract_2023_2024/assets/115353472/d135fa60-cb48-493f-beb7-e687d276a544)/>

| Function | Delta |
|----------|-------|
| ?::f()   |   ?   |
| ?::g()   |   ?   |
| ?::h()   |   ?   |
| ?::k()   |   ?   |

**Здача 3.** Какво ще се отпечати на конзолата след изпълнение на кода?

```c++
struct A
{
    A() { std::cout << "A()" << std::endl; }
    A(int) { std::cout << "A(int)" << std::endl; }
    A(int, int) { std::cout << "A(int, int)" << std::endl; }
    A(int, int, int) { std::cout << "A(int, int, int)" << std::endl; }
};

struct B : virtual A
{
    B() : A() { std::cout << "B()" << std::endl; }
    B(int) : A(1) { std::cout << "B(int)" << std::endl; }
};

struct C : virtual A
{
    C() : A(1, 1) { std::cout << "C()" << std::endl; }
    C(int) : A(1, 1, 1) { std::cout << "C(int)" << std::endl; }
};

struct D : virtual B
{
    D() : A(1, 1), B(1) { std::cout << "D()" << std::endl; }
};

struct E : C, D
{
    E(): B(1), C(1), D() { std::cout << "E()" << std::endl; }
};

int main()
{
    E e;
}
```
