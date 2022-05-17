#include <iostream>
#include "Bar/Bar.h"

int main()
{
	Bar b;

	b.addDrink(Drink("Coke", 330), 2); //2x Coca cola 330 ml

	b.addDrink(Drink("Fanta", 500));   //1x Fanta 500 ml

	b.addAlcoholDrink(AlcoholDrink("Zagorka", 500, 5)); //1x Zagorka, 5% alc,  500 ml

	std::cout << b.getAlcDrink().getName() << std::endl; // Zagorka 

	std::cout << b.getDrink().getName() << std::endl; // Coke
	std::cout << b.getDrink().getName() << std::endl; // Coke 
	std::cout << b.getDrink().getName() << std::endl; // Fanta 

	std::cout<<	b.getStats().soldAlcoholDrinks << std::endl; // 1
	std::cout << b.getStats().soldDrinks << std::endl; // 3

}