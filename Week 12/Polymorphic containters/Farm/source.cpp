#include <iostream>
#include "Collection/Farm.h"
#include "Animals/Animal.h"
#include "Factory/AnimalFactory.h"

int main()
{
	Farm f;
	f.addAnimal(AnimalType::Dog);
	f.addAnimal(AnimalType::Cat);
	f.addAnimal(AnimalType::Cow);

	f.roarAll();
	
	std::cout << (int)f.getTypeByIndex(0) << std::endl;
}