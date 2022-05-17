#pragma once
#include "../Queue/Queue.hpp"
#include "../Pair/Pair.hpp"
#include "../AlcoholDrink/AlcoholDrink.h"

class Bar
{
	MyQueue<Pair<AlcoholDrink, size_t>> alcoholDrinks;
	MyQueue<Pair<Drink, size_t>> drinks;

public:
	struct Statistics
	{
		size_t soldDrinks;
		size_t soldAlcoholDrinks;
		size_t mlSold;
	} stats;


	Bar() = default;

	void addAlcoholDrink(const AlcoholDrink& dr, size_t count = 1);
	void addDrink(const Drink& dr, size_t count = 1);


	Drink getDrink();
	AlcoholDrink getAlcDrink();

	const Statistics& getStats() const;

};
