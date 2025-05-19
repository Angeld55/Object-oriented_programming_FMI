#include "Farm.h"
#include "Animal.h"

Farm::Farm() 
{
	capacity = 8;
	animals = new Animal * [capacity] {nullptr};
}

Farm::Farm(const Farm& other)
{
	copyDynamic(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);
		capacity = other.capacity;
		count = other.count;
	}
	return *this;
}

Farm::~Farm()
{
	freeDynamic();
}

int Farm::getTypeCode(int index) const
{
	return animals[index]->getType();
}

void Farm::roarAll() const
{
	for (int i = 0; i < count; i++)
		animals[i]->roar();  //polymorphism
}

void Farm::resize()
{
	Animal** newArr = new Animal * [capacity *= 2];
	for (int i = 0; i < count; i++)
		newArr[i] = animals[i]; //copy the pointer!
	delete[] animals;
	animals = newArr;
}

void Farm::addAnimal(Animal* animal) 
{
	if (!animal)
		return;
	if (count == capacity)
		resize();
	animals[count++] = animal;
}

void Farm::addAnimal(const Animal* animal) 
{
	if (!animal)
		return;
	if (count == capacity)
		resize();
	animals[count++] = animal->clone(); //polymorphism
}

void Farm::copyDynamic(const Farm& other)
{
	animals = new Animal * [other.capacity];
	for (int i = 0; i < other.count; i++)
		animals[i] = other.animals[i]->clone();// не се инт кой е обектът ??
} //polymorphism

void Farm::freeDynamic()
{
	for (int i = 0; i < count; i++)
		delete animals[i]; //works, couse we have virt. destructor!!
	delete[] animals;
}

