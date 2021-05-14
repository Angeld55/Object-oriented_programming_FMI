#include "Bar.h"

void Bar::addDrink(const char* name, int ml)
{
	drinks.enqueue(Drink(name, ml));
}
void Bar::addAlocoholDrink(const char* name, int ml, int alcohol)
{
	alcoholDrinks.enqueue(AlcoholDrink(name, ml, alcohol));
}

Drink Bar::getDrink()
{
	Drink d = drinks.dequeue();
	incrementStatistics(d);
	return d;
}
AlcoholDrink Bar::getAcloholDrink()
{
	AlcoholDrink d = alcoholDrinks.dequeue();
	incrementStatistics(d, true);
	return d;
}

void Bar::incrementStatistics(const Drink& dr, bool isAlcoholDrink)
{
	stats.mlSold += dr.getMl();
	stats.allDrinksSold++;

	if (isAlcoholDrink)
		stats.alcoholDrinksSold++;
}

size_t Bar::getMlSold() const
{
	return stats.mlSold;
}
size_t Bar::getAllDrinksSold() const
{
	return stats.allDrinksSold;
}
size_t Bar::getAlcoholDrinksSold() const
{
	return stats.alcoholDrinksSold;
}
