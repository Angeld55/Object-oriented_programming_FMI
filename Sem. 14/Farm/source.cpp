#include <iostream>
#include "../Farm/Collection/Farm.h"

int main()
{
	Farm myFarm;

	while (1)
	{
		size_t animalId;
		std::cin >> animalId;
		bool result = myFarm.addAnimal((Animal::AnimalType)animalId);
		
		if (result)
			std::cout << "Added animal of type: " << myFarm.getTypeByIndex(myFarm.getCount() - 1) << std::endl;
		else
			std::cout << "Invalid animal type" << std::endl;
	}
}