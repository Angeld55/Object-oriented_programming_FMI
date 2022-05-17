#pragma once
#include "AlcoholDrink.h"

AlcoholDrink::AlcoholDrink():alcP(5) {}

AlcoholDrink::AlcoholDrink(const MyString& name, int ml, int alcP) :Drink(name, ml)
{
	setAlcP(alcP);
}
void AlcoholDrink::setAlcP(int alcP)
{
	if (alcP < 5 || alcP > 98)
		alcP = 50;
	this->alcP = alcP;
}
int AlcoholDrink::getAlcP() const
{
	return alcP;
}