#pragma once
#include "../Animals/Animal.h"
#include "../Factory/Factory.h"

class Farm
{
	Animal** animals;
	size_t animalsCount;
	size_t capacity;

	void free();
	void copyFrom(const Farm& other);
	void resize();

	AnimalFactory factory; //better singelton

public:
	Farm();
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);
	~Farm();

	void addAnimal(const Animal& animal);
	bool addAnimal(Animal::AnimalType animalType);

	void allSayHello() const;

	size_t getCount() const;
	bool isEmpty() const;

	Animal::AnimalType getTypeByIndex(size_t index) const;
};
