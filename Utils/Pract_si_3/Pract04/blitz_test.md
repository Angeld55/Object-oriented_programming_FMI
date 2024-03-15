## Задачи Blitz Test №1

**1.** Има ли проблем със следния код? Ако да, какъв?
```c++
#include <iostream>

void f(char* ptr, unsigned n) {
	ptr = new char[n];
	for (int i = 0; i < n; i++)
		std::cin >> ptr[i];
}

int main() {
	char* ptr = nullptr;
	unsigned n = 10;
	f(ptr, n);
	delete[] ptr;
}
```

**2.** Какво връщат sizeof и alignof на следните структури?
```c++
struct Empty {};

struct A{
	Empty obj1;
	int a;
	char b;
	double c[3];
};
```

**3.** В двоичен файл трябва да се запише масив от цели числа с размер 5. 
```c++
int main() {
	std::ofstream file("myFile.dat", std::ios::out | std::ios::binary);
	if (!file.is_open()) {
		return -1;
	}
	int arr[5] = { 1, 2, 3, 4, 5 };
}
```

Отбележете всички **правилни начини**, по които да се запише arr във file.
- a) file.write((const char*)arr, sizeof(arr));
- b) file.write((char*)arr, sizeof(arr));
- c) file.write((const char*)arr, 5*sizeof(int));
- d) file.write((char*)arr, 5*sizeof(int));
- e) нито един от изброените варианти не е верен


**4.** Отворили сте файл в режим за четене със следното съдържание:

**"OOP blitz test 2024"**

*Забележка: Кавичките не се броят към съдържанието на файла*

Какво ще се изведе на конзолата след изпълнение на следния код?
```c++
char symbol;
file.seekg(5, ios::beg);
symbol = file.get();
std::cout << symbol << std::endl;
file.seekg(-4, ios::cur);
symbol = file.get();
std::cout << symbol << std::endl;
file.seekg(-2, ios::end);
symbol = file.get();
std::cout << symbol << std::endl;
file.seekg(-1, ios::cur);
symbol = file.get();
std::cout << symbol << std::endl;
```

**5.** Какво ще отпечата следният код на екрана?
```c++
union {
	uint64_t number = 0;
	char str[8];
} example;

int main() {
	example.number = 3;
	example.str[1] = 1;
	std::cout << example.number;
}
```
