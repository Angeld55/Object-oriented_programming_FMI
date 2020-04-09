#pragma once

#include "Drink.h"

class AlcoholDrink : public Drink
{
private:
	int percentAlcohol;

public:
	AlcoholDrink(const char* mark, int ml, int percentAlcohol);
	void setAlcohol(int alcohol);
	int AlcoholDrink::getAlcohol() const;
};
