#pragma warning(disable: 4996)


#include <iostream>
#include "Bar/Bar.h"
#include "Drinks/EnergyDrink.h"

using namespace std;

int main()
{	
	Bar b;

	b.addDrink("Coke", 330);

	b.addDrink("Fanta", 500);

	b.addAlocoholDrink("Zagorka", 500, 5);

	cout << b.getDrink().getName()<<endl;
	cout << b.getDrink().getName() << endl;

	cout << b.getAcloholDrink().getName() << endl;

	cout << b.getAllDrinksSold() << endl;

	EnergyDrink energyDrink("Monster", 500, "ECAS");
	
	std::cout << energyDrink.getCertifiate();
}
