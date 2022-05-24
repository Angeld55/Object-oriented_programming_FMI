
# Виртуални таблици. Ключови думи override и final. Колекции от обекти в полиморфна йерархия. Копиране и триене.
## Виртуални таблици.

Виртуални таблици - таблица с указатели към функции. 

```c++
struct A
{
	virtual int f()
	{
		return 1;
	}
	virtual int g()
	{
		return 1;
	}
};

struct B : public A
{
	int f() override
	{
		return 2;
	}
};

struct C : public B
{
	int f() override
	{
		return 3;
	} 
	int g() override
	{
		return 3;
	}
};


 ```


![enter image description here](https://i.ibb.co/dbzJTtm/vtable-2-1.png)

## override и final
 - override указва, че дадена функция презаписва функция от базовия клас. Ако в базовия клас няма такава функция, то кодът няма да се компилира.
 - final указва, че дадена функция не може да се презависва надолу по йерархията или че даден клас не може да се наследява.
## Колекция.

Можем да реализираме колекция от различни типове (но с общ базов клас), чрез масив от указатели. Указателите трябва да са от типа на базовия клас.

```c++
struct Fruit
{
	virtual void printColor() const = 0;
	
	virtual ~Fruit(){}
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
	
	void addApple();
    	void addOrange();
     	void addLemon(size_t sourness);
};

void FruitStore::addApple()
{
	fruits[count++] = new Apple();
}

void FruitStore::addOrange()
{
	fruits[count++] = new Orange();
}
void FruitStore::addLemon(size_t sourness)
{
	fruits[count++] = new Lemon(sourness);
}
 ```

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
		fruits[i] = other.fruits[u]->clone();
	count = other.count;
	capacity = other.capacity;
}
 ```

