#include "Bar.h"

void Bar::addAlcoholDrink(const AlcoholDrink& dr, size_t count)
{
	if (count > 0)
		alcoholDrinks.push(Pair<AlcoholDrink, size_t>(dr, count));
}
void Bar::addDrink(const Drink& dr, size_t count)
{
	if (count > 0)
		drinks.push(Pair<Drink, size_t >(dr, count));
}

Drink Bar::getDrink()
{

	if (drinks.isEmpty())
		throw std::logic_error("Empty drinks collection");

	Drink toReturn = drinks.peek().getFirst();

	stats.mlSold += toReturn.getMl();
	stats.soldDrinks++;

	drinks.peek().setSecond(drinks.peek().getSecond() - 1);
	if (drinks.peek().getSecond() == 0)
		drinks.pop();

	return toReturn;
}

AlcoholDrink Bar::getAlcDrink()
{
	if (alcoholDrinks.isEmpty())
		throw std::logic_error("Empty alc. drinks collection");

	AlcoholDrink toReturn = alcoholDrinks.peek().getFirst();

	stats.mlSold += toReturn.getMl();
	stats.soldAlcoholDrinks++;

	alcoholDrinks.peek().setSecond(alcoholDrinks.peek().getSecond() - 1);
	if (alcoholDrinks.peek().getSecond() == 0)
		alcoholDrinks.pop();

	return toReturn;

}

const Bar::Statistics& Bar::getStats() const
{
	return stats;
}