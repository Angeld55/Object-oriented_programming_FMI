#pragma once

#include "Drink.h"

class AlcoholDrink : public Drink 
{
	int alcoholPercentage;

public:
	AlcoholDrink();
	AlcoholDrink(const char* name, int ml, int alcoholPercentage);

	int getAlcoholPercentage() const;
	void setAlcoholPercentage(int alcoholPercentage);
};