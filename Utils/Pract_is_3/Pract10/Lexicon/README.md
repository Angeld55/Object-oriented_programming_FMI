# Тест - Наследяване

#### 1. Какво ще се отпечата на конзолата при изпълнение на този код
```c++

class A {
public:
    A() { std::cout << "A()"; }

    ~A() { std::cout << "~A()"; }
};

class B {
public:
    B() { std::cout << "B()"; }

    ~B() { std::cout << "~B()"; }
};

class Base {
public:
    A obj1;

	Base() { std::cout << "Base()"; }

	~Base() { std::cout << "~Base()"; }
};

class Der : public Base {
public:

    B obj2;
	Der() { std::cout << "Der()"; }

	~Der() { std::cout << "~Der()"; }
};
```

```c++
int main() {
    Der obj;
}
```

#### 2. Ще се компилира ли следния код? Ако не се, посочете реда и причината.

```c++
class Base {};

class Der : public Base {};

int main()
{
	Base* ptr1 = new Der();
	Der* ptr = new Base();
}
```

#### 3. Какво ще се отпечата на конзолата при изпълнение на този код
```c++
class A {
	int a;
public:
	A(int a) {}
	A(const A& other) {
		std::cout << "A(copy)";
	}
	A(A&& other) noexcept {
		std::cout << "A(move)";
	}
	A& operator=(const A& other) {
		std::cout << "A=copy";
		return *this;
	}
	A& operator=(A&& other) noexcept {
		std::cout << "A=move";
		return *this;
	}
};

int main() {
	A obj = 5;
	obj = 1;
}
```
#### 4. Ще се компилира ли следния код? Ако се компилира, кажете какво се извежда, ако не се - посочете грешката.

```c++
class Base {
public:
    void f() {std::cout << "f() from Base";}
};

class Der : public Base {
public:
    void f() {std::cout << "f() from Der";}
};

int main {
    Der obj;
    obj.f();
    obj.Base::f();
}
```
#### 5. Ще се компилира ли следния код? Ако се компилира, кажете какво се извежда, ако не се - посочете грешката.

```c++
class Base {
public:
	int a;
	Base(int a) { this->a = a; }
};

class Der : public Base {
public:
	int b;
	Der(int a, int b) : Base(a) { this->b = b; }
};

void f(Base* arr) { std::cout << arr[1].a; }
void g(Der* arr) { std::cout << arr[1].a; }

int main() {
	Der arr[3] = { {1,3}, {4,1}, {1,2} };
	f(arr);
	g(arr);
}
```
#### 6. Ще има ли разлика в представянето на паметта на обектите, създадени от класа Der в двата варианта. Обосновете се.

### I вариант
```c++
class Base {
    int a;
};

class Der : public Base {
    int b;
};
```
### II вариант
```c++
class Base {
    int a;
};

class Der {
    Base obj;
    int b;
};
```
#### 7. Какво ще отпечата следният код?
```c++
class A {
    unsigned a = 4;
public:
    int x = 1;
    int y = 2;
    void f() const;
    A(unsigned a, int x, int y) : a(a), x(x), y(y) {}
    A() = default;
};


struct X : public A {
    double b;
    X() : A(100, 200, 300), b(3.14) {}
};

int main()
{
    X obj;
    std::cout << ((int*)&obj)[1];
}
```


#### 8. Кой от редовете ще се изпълни 
```c++
class Base {

};

class Der : public Base {

};

void f1(const Base& base);
void f2(Base& base);
void f3(const Base* base);
void f4(Base* base);
void f5(Base base);
void f6(const Der& der);
void f7(Der& der);
void f8(const Der* der);
void f9(Der* der);
void f10(Der der);

int main() {
	Der d;
	f1(d);
	f2(d);
	f3(&d);
	f4(&d);
	f5(d);
	f6(d);
	f7(d);
	f8(&d);
	f9(&d);
	f10(d);
}
```

#### 9. Ще се изпълни ли следният код: 
```c++
class A {};
class B : public A {};
class C : protected A {};
class X : public B {};

void f(A obj) {};

int main() {
	X obj;
	f(obj);
}
```

#### 10. Има ли грешка в дефиницията на operator= на Der? Ако да, посочете и я поправете
```c++
class Der : public Base {
    //...
	void free() {/*...*/ }
	void copyFrom(const Der& other) {/*...*/ }
public:
    //...
	Der& operator=(const Der& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
};
```

#### Бонус: Как ще реализирате функциите getCallCount() и call(), така че getCallCount() да връща броят извиквания на call()?

```c++
struct Callable {
	//...
	void getCallCount() const { ... }
	void call() const { ... }
};
```
