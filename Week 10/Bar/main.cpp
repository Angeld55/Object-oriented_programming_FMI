#include <iostream>
#include "MyString/MyStringSso.h"


//TBI ..


bool isCapital(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
class Drink
{
	MyString name;
	unsigned ml;
public:

	Drink(const MyString& name, unsigned ml)
	{
		setName(name);
		setMl(ml);
	}

	void setName(const MyString& str)
	{
		if (str.length() >= 1 && isCapital(str[0]))
		{
			name = str;//copy!!
		}
	}

	void setMl(unsigned ml)
	{
		if (ml < 200 || ml > 1000)
			ml = 200;
		this->ml = ml;
	}

	const MyString& getName() const
	{
		return name;
	}

	unsigned getMl() const
	{
		return ml;
	}
};


class AlcoholDrink : public Drink
{
private:
	unsigned alcohol;
public:
	AlcoholDrink(const MyString& drinkName, unsigned ml, unsigned alcohol) : Drink(drinkName, ml)
	{
		setAlcohol(alcohol);
	}

	void setAlcohol(unsigned alc)
	{
		if (alc < 5 || alc > 98)
		{
			alc = 5;
		}
		alcohol = alc;
	}

	unsigned getAlcohol() const
	{
		return alcohol;
	}
};


class Bar
{
public:

	struct BarStats
	{
		unsigned drinksSold = 0;
		unsigned alcDrinksSold = 0;
		unsigned mlSold = 0;
	};
private:

	Drink drinks[100];
	size_t drinksCount = 0;

	AlcoholDrink alcDrinks[100];
	size_t alcoholDrinksCount = 0;
	BarStats stats;

	unsigned countOfDrinks[100]; ///[drink drink ........ alcdrink alcdrink] 

	unsigned searchMaxDrinkCount() const
	{
		unsigned max = 0;
		unsigned maxIndex = 0;
		for (unsigned i = 0; i < drinksCount; i++)
		{
			if (countOfDrinks[i] > countOfDrinks[maxIndex])
				maxIndex = i;
		}
		return maxIndex;
	}

public:


	void addDrink(const MyString& str, unsigned ml, unsigned count)
	{
		Drink dr(str, ml);
		drinks[drinksCount] = dr;
		countOfDrinks[drinksCount++] = count;

	}
	void addAlcoholDrink(const MyString& str, unsigned ml, unsigned alc, unsigned count)
	{
		AlcoholDrink dr(str, ml, alc);
		alcDrinks[alcoholDrinksCount++] = dr;
		countOfDrinks[100 - alcoholDrinksCount] = count;
	}

	Drink getDrink()
	{
		unsigned ind = searchMaxDrinkCount();	
		countOfDrinks[ind]--;

		stats.drinksSold++;

		if (countOfDrinks[ind] == 0)
		{
			Drink copy = drinks[ind];
			//изтриваме я от  drinks[ind]
			return copy; 
		}
		else
			return drinks[ind];
	}

	const BarStats& getStats() const;

};

const Bar::BarStats& Bar::getStats() const
{
	return stats;
}

int main()
{
	AlcoholDrink d("dsfsdf", 4, 4);

	f(&d);
}