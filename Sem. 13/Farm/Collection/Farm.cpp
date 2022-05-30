#include "Farm.h"

void Farm::free()
{
	for (size_t i = 0; i < animalsCount; i++)
		delete animals[i];  //не се инт. какъв обект е. (вирт дестр)
	delete[] animals;
}
void Farm::copyFrom(const Farm& other)
{
	animals = new Animal * [other.capacity];
	animalsCount = other.animalsCount;
	capacity = other.capacity;

	for (size_t i = 0; i < animalsCount; i++)
	{
		animals[i] = other.animals[i]->clone();
	}
}
void Farm::resize()
{
	Animal** newCollection = new Animal * [capacity *= 2];
	for (size_t i = 0; i < animalsCount; i++)
		newCollection[i] = animals[i]; // !!не правим клониране
	delete[] animals;
	animals = newCollection;
}
void Farm::addAnimal(const Animal& currentAnimal)
{
	if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = currentAnimal.clone();
}

Farm::Farm()
{
	capacity = 8;
	animalsCount = 0;
	animals = new Animal * [capacity];
}
Farm::Farm(const Farm& other)
{
	copyFrom(other);
}
Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Farm::~Farm()
{
	free();
}

void Farm::allSayHello() const
{
	for (size_t i = 0; i < animalsCount; i++)
		animals[i]->sayHello();
}
