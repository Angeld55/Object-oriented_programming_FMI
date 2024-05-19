#pragma once
#include "../Animals/Animal.h"


//Bonus task: Handle the possible alloc exceptions in the class
//It's not required on the exam.

class Farm
{
	Animal** animals;
	size_t animalsCount;
	size_t capacity;

	void free();
	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void resize();
	

public:
	Farm();
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);
	~Farm();

	Farm(Farm&& other) noexcept;
	Farm& operator=(Farm&& other) noexcept;

	void addAnimal(AnimalType animalType);
	void addAnimal(const Animal& animal);
	void roarAll() const;

	AnimalType getTypeByIndex(unsigned index) const;
};
