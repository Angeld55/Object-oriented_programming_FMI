#include "Farm.h"
#include "../Factory/AnimalFactory.h"
//The factory is in a seperate file, so we don't have to 
//move include the animals in this file

void Farm::free()
{
	for (size_t i = 0; i < animalsCount; i++)
		delete animals[i];  //не се инт. какъв обект е. (вирт дестр)
	delete[] animals;
}

void Farm::copyFrom(const Farm& other)
{
	animals = new Animal*[other.capacity];
	animalsCount = other.animalsCount;
	capacity = other.capacity;

	for (size_t i = 0; i < animalsCount; i++)
		animals[i] = other.animals[i]->clone();
}

void Farm::moveFrom(Farm&& other)
{
	animalsCount = other.animalsCount;
	capacity = other.capacity;

	animals = other.animals;
	other.animals = nullptr;

	other.animalsCount = other.capacity = 0;
}

void Farm::resize()
{
	Animal** newCollection = new Animal * [capacity *= 2];
	for (size_t i = 0; i < animalsCount; i++)
		newCollection[i] = animals[i]; // !!не правим клониране
	delete[] animals;
	animals = newCollection;
}


void Farm::addAnimal(AnimalType animalType)
{
	if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = animalFactory(animalType);
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

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}
Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Farm::roarAll() const
{
	for (size_t i = 0; i < animalsCount; i++)
		animals[i]->roar();
}

AnimalType Farm::getTypeByIndex(unsigned i) const
{
	if (i > animalsCount)
		throw std::out_of_range("Invalid index");
	return animals[i]->getType();
}