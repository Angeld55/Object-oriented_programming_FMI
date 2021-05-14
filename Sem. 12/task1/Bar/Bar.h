#pragma once
#include <iostream>
#include "../Drinks/AlcoholDrink.h"
#include "../Queue/Queue.hpp"



class Bar
{
	struct Statistics
	{
		size_t mlSold = 0;
		size_t allDrinksSold = 0;
		size_t alcoholDrinksSold = 0;
	};

private:
	Queue<Drink> drinks;
	Queue<AlcoholDrink> alcoholDrinks;

	Statistics stats;

	void incrementStatistics(const Drink& dr, bool isAlcoholDrink = false);

public:

	void addDrink(const char* name, int ml);
	void addAlocoholDrink(const char* name, int ml, int alcohol);

	Drink getDrink();
	AlcoholDrink getAcloholDrink();

	size_t getMlSold();
	size_t getAllDrinksSold();
	size_t getAlcoholDrinksSold();
};