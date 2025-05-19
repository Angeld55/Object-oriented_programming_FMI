#include <iostream>
#include "Farm.h"
#include "Factory.h"


int main()
{
	Farm f;
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		f.addAnimal(animalFactory());
	f.roarAll();

} //~Farm() -->  deletes all animals

