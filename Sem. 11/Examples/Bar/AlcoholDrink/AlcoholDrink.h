#pragma once
#include "../Drink/Drink.h"
#include "../Queue/Queue.hpp"
#include "../Pair/Pair.hpp"

class AlcoholDrink : public Drink
{
	int alcP;
public:
	AlcoholDrink();
	AlcoholDrink(const MyString& name, int ml, int alcP);
	
	void setAlcP(int alcP);
	int getAlcP() const;
};