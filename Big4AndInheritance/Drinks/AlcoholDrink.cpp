include "AlcoholDrink.h"


AlcoholDrink::AlcoholDrink(const char* mark, int ml, int percentAlcohol) : Drink(mark,ml)
{
	setAlcohol(percentAlcohol);
}
void AlcoholDrink::setAlcohol(int alcohol)
{
	if (alcohol < 4 || alcohol>98)
		alcohol = 20;
	percentAlcohol = alcohol;
}
int AlcoholDrink::getAlcohol() const
{
	return alcohol;
}
