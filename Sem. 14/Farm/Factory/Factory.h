#include "../Animals/Animal.h"
#include "../Animals/Dog.h"
#include "../Animals/Cat.h"
#include "../Animals/Mouse.h"

class AnimalFactory
{
public:
	virtual Animal* createAnimal(Animal::AnimalType type);
};