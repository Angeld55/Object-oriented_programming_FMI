# Ред на извикване на конструктори и деструктори

<h2>За примерите показани по-долу приемете, че структурите, от които създаваме инстанции имат конструктор и деструктор от следния вид:</h2>

Пример 1:
```c++
struct A {
    A() { std::cout << "A()\n"; }
    ~A() { std::cout << "~A()\n"; }
};
```

Пример 2:
```c++
int main() {
    А obj1;
    B obj2;
    return 0;
}
```

Пример 3:
```c++
int main() {
    А* ptr = new А();
    return 0;
}
```

Пример 4:
```c++
int main() {
    А* ptr = new А();
    delete ptr;
    return 0;
}
```

Пример 5:
```c++
А globalObj;

int main() {
    std::cout << "Inside main()" << std::endl;
    А localObj;
    return 0;
}
```

Пример 6:
```c++
void func(const А& obj) {
    std::cout << "Inside func()" << std::endl;
}

int main() {
    std::cout << "Before func()" << std::endl;
    А obj;
    func(obj);
    std::cout << "After func()" << std::endl;
    return 0;
}

```

Пример 7:
```c++
void func(А obj) {
    std::cout << "Inside func()" << std::endl;
}

int main() {
    std::cout << "Before func()" << std::endl;
    А obj;
    func(obj);
    std::cout << "After func()" << std::endl;
    return 0;
}

```

Пример 8:
```c++
int main() {
    if (4) {
        A obj;
    }
    std::cout << "After if block" << std::endl;
    return 0;
}

```

Пример 9:
```c++
struct C {
    int x;
    C(int x) {
        this->x = x; 
        std::cout << "C(" << x << ")\n";
    }
    ~C() { std::cout << "~C(" << x << ")\n"; }
};

void func2(C obj) {
    std::cout << "Inside func2" << std::endl;
}

void func1(B obj) {
    std::cout << "Inside func1" << std::endl;
    func2(5);
}

int main() {
    func1(new B());
    return 0;
}

```

Пример 10:
```c++
struct C {
    A obj1;
    B obj2;
    C() { std::cout << "C()\n"; }
    ~C() { std::cout << "~C()\n"; }
};

int main() {
    C myObj;
    return 0;
}

```

Пример 11:
```c++
struct C {
    C() { std::cout << "C()\n"; }
    ~C() { std::cout << "~C()\n"; }
};

int main() {
    C myObj();
    return 0;
}

```

Подсказка: *не се компилира*