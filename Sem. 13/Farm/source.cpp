#include <iostream>
#include "Farm.h"
#include "Dog.h"
#include "Cat.h"
#include "Mouse.h"

int main()
{
	Farm f;
	f.addAnimal(Dog());
	f.addAnimal(Cat());

	f.allSayHello();
}