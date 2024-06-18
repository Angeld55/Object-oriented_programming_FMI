## Хетерогенен контейнер.

Можем да реализираме колекция от различни типове (но с общ базов клас), чрез масив от указатели. Указателите трябва да са от типа на базовия клас.

```c++
struct Fruit
{
	virtual void printColor() const = 0;
	
	virtual ~Fruit() = default;
};

struct Apple : public Fruit
{
	 void printColor() const override
	{
		std::cout << "Red or green! "<<std::endl;
	}
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange! "<<std::endl;
	}
	
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	void printColor() const override
	{
		std::cout << "Yellow! "<<std::endl;
	}
};

class FruitStore
{
private:
	Fruit** fruits;
	size_t capacity;
	size_t count;
          
    void copyFrom(const FruitStore& other);
    void free();
    
public:
	FruitStore();
	FruitStore(const FruitStore&);
	FruitStore& operator=(const FruitStore&);
       ~FruitStore();
	
	void addFruit(Fruit* fr);
};

void FruitStore::addFruit(Fruit* fr)
{
	fruits[count++] = fr;
}
int main()
{
	FruitStore store;
	store.addFruit(new Lemmon(3));
	store.addFruit(new Apple());
}

## Триене
Понеже имаме виртуален деструктор в базовия клас, не се интересуваме в колекцията какви са обектите, които трием.
```c++
void FruitStore::free()
{
	for(int i = 0; i < count; i++)
		delete fruits[i];
	delete[] fruits;
}
 ```

## Копиране
Искаме да реализираме копиране на колекцията.
Това трябва да стане без да нарушаваме абстракцията - искаме обеките да се копират без да се налага да запитваме за техния тип.
За това дефинираме виртуална функция clone, която ще връща копие на обекта. Тази функция я разписваме във всеки от наследниците.

```c++

struct Fruit
{
	virtual void printColor() const = 0;
	virtual ~Fruit(){}

      	virtual Fruit* clone() const = 0; //!
};

struct Apple : public Fruit
{
	 void printColor() const override
	{
		std::cout << "Red or green! "<<std::endl;
	}
	Fruit* clone() const override
	{
		return new Apple(*this);
    	}
	
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange! "<<std::endl;
	}
	
	Fruit* clone() const override
	{
		return new Orange(*this);
	}
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	void printColor() const override
	{
		std::cout << "Yellow! "<<std::endl;
	}
	Fruit* clone() const override
	{
		return new Lemon(*this);
    	}
};
 ```
От тук копирането става тривиално:
```c++
void FruitStore::copyFrom(const FruitStore& other)
{
	fruits = new Fruit*[other. capacity];
	for(int i = 0; i < other.count; i++)
		fruits[i] = other.fruits[i]->clone();
	count = other.count;
	capacity = other.capacity;
}
 ```


## Шаблони
Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас
```c++
#include <iostream>
using namespace std;

template <class T>
T sum(const T& a, const T& b)
{
    return a + b;
}

int main()
{
    int a = 4;
    int b = 9;
    cout << sum<int>(a, b) << endl;

    double c = 3.14;
    double d = 4.5;
    cout << sum<double>(c,d) << endl;
	
    return 0;
}
```
Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

**Задача 1:**
Релизирайте структурата от данни опашка. Опашката трябва да работи с **произволни типове**. След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат премахнати всички елементи преди него в реда, в който са добавени.

**Пример**:
 ```c++
int main()
{
	queue<int> q;
	q.push(3);
	q.push(5);
	q.push(10);

	cout << q.peek() << endl; //3
	q.pop();
	
	cout << q.peek() << endl; //5
	q.pop();

	cout << q.peek() << endl; //10
	q.pop();
	
	cout << q.isEmpty() << endl; //1	
}
 ```
  **Задача 2:**
 Създайте **шаблонна** опашка с k приоритета. При взимане на елемент от опашката трябва да се връща най-отдавна добавения елемент от тези с най-висок приоритет.
 
  ```c++
int main()
{
	kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.
	
	q.push('A',0): //adds A with lowest priority: 0
	q.push('B',3);
	q.push('C',2);
	q.push('D',2);
	q.push('E',1);
	
	//q.push('F', 5); //error! No such priority!
	
	q.peek(); // B
	q.pop();
	
	q.peek(); // C
	q.pop();
	
	q.peek(); // D
	q.pop();
	
	q.peek(); // E
	q.pop();
	
	q.peek(); // A
	q.pop();
}
 ```

