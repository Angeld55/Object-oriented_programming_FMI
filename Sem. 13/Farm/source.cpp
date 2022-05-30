#include <iostream>
#include "Collection/Farm.h"
#include "Animals/Dog.h"
#include "Animals/Cat.h"
#include "Animals/Mouse.h"

int main()
{
	Farm f;
	f.addAnimal(Dog());
	f.addAnimal(Cat());

	f.allSayHello();
}