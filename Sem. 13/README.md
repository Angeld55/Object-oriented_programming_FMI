
# Колекции от обекти в полиморфна йерархия. Копиране и триене.
## Колекция.

Можем да реализираме колекция от различни типове (но с общ базов клас), чрез масив от указатели. Указателите трябва да са от типа на базовия клас.

```c++
struct Fruit
{
	virtual void printColor() const = 0;
	
	virtual ~Fruit(){}
};

struct Apple
{
	 void printColor() const override
	{
		std::cout << "Red or green! "<<std::endl;
	}
};

struct Orange
{
	void printColor() const override
	{
		std::cout << "Orange! "<<std::endl;
	}
	
};

struct Lemon
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

struct Apple
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

struct Orange
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

struct Lemon
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

