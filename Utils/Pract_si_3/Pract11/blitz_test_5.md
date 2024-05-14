## Blitz Test №5

**Задача 1.** Какво ще се отпечата?
```c++
#include <iostream>
using namespace std;

class Base
{
  public:
  Base() { cout << "Base"; }
};

class Derived : public Base
{
  public:
  Derived(int i) { cout << i; }
};

int main()
{
  Derived d2(10);
  return 0;
}
```

**Задача 2.** Какво ще се отпечата?
```c++
#include <iostream>
using namespace std;

class A
{
  int x;
};

class B : public A
{
  public:
  void show()
  {
    x=10;
    cout << x;
  }
};

int main()
{
  B b;
  b.show();
  return 0;
}
```

**Задача 3.** Какво ще се отпечата?

```c++
#include <iostream>
#include <string>
using namespace std;
class A
{
	int a, b;// sizeof(int) = 4
	float d;// sizeof(float) = 4
	bool bl;// sizeof(bool) = 1 
   
};
 
class B: private A
{
    bool bl;
};
 
int main(int argc, char const *argv[])
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B);
	return 0;
}
```

**Задача 4.** Какво ще се отпечата?

```c++
#include <iostream>
#include <string>
using namespace std;
class A
{
	float d;
    public:
	int a;
	void change(int i){
		a = i;
	}
	void value_of_a(){
		cout<<a<<endl;
	}
};
 
class B: public A
{
	int a = 15;
    public:
	void print(){
		cout<<a<<endl;
	}
};
 
int main(int argc, char const *argv[])
{
	B b;
	b.change(10);
	b.print();
	b.value_of_a();
 
	return 0;
}
```

**Задача 5.** Какво ще се отпечата?

```c++
#include <iostream>
#include <string>
using namespace std;

class MyException : public logic_error {
public:
    MyException(const string& message) : logic_error(message) {}
};

int main(int argc, char const* argv[]) {
    try {
        throw MyException("Custom exception occurred!");
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    } catch (const MyException& e) {
        cout << "Caught MyException: " << e.what() << endl;
    }

    return 0;
}
```
