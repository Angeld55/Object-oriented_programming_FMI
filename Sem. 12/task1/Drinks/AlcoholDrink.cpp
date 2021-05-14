#include "AlcoholDrink.h"

AlcoholDrink::AlcoholDrink() : AlcoholDrink("Unknown", 0, 0){}

AlcoholDrink::AlcoholDrink(const char* name, int ml, int alcoholPercentage) : Drink(name, ml)
{
	setAlcoholPercentage(alcoholPercentage);
}
int AlcoholDrink::getAlcoholPercentage() const
{
	return alcoholPercentage;
}
void AlcoholDrink::setAlcoholPercentage(int alcoholPercentage)
{
	const int MINPERCENTAGE = 1;
	const int MAXPERCENTAGE = 97;

	this->alcoholPercentage = MINPERCENTAGE;

	if (MINPERCENTAGE <= alcoholPercentage && alcoholPercentage <= MAXPERCENTAGE)
		this->alcoholPercentage = alcoholPercentage;

}