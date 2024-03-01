#include <iostream>

enum Drink : uint8_t
{
	WHISKEY = 1 << 0,
	VODKA = 1 << 1,
	COLA = 1 << 2,
	FANTA = 1 << 3,
	WATER = 1 << 4,
	WINE = 1 << 5,
	RHUM = 1 << 6,
	JUICE = 1 << 7,
	END = 1 << 8
};

struct Client
{
	char name[32];
	uint8_t favDrinks;
};

bool likesDrink(const Client& client, Drink drink)
{
	return (client.favDrinks & drink) != 0;
}

void changeToLike(Client& client, Drink drink)
{
	client.favDrinks |= drink;
}

void changeToDislike(Client& client, Drink drink)
{
	client.favDrinks &= ~drink;
}

void printDrink(Drink drink)
{
	switch (drink)
	{
	case WHISKEY:
		std::cout << "whiskey";
		break;
	case VODKA:
		std::cout << "vodka";
		break;
	case COLA:
		std::cout << "cola";
		break;
	case FANTA:
		std::cout << "fanta";
		break;
	case WATER:
		std::cout << "water";
		break;
	case WINE:
		std::cout << "wine";
		break;
	case RHUM:
		std::cout << "rhum";
		break;
	case JUICE:
		std::cout << "juice";
		break;
	default:

		break;
	}
}

Drink iterateDrink(Drink drink)
{
	return Drink(drink << 1);
}

Drink startDrink()
{
	return WHISKEY;
}

Drink endDrink()
{
	return END;
}

void printAllDrinks(const Client& client)
{
	std::cout << client.name << " likes ";
	for (Drink i = startDrink(); i != endDrink(); i = iterateDrink(i))
	{
		if (likesDrink(client, i))
		{
			printDrink(i);
			std::cout << ", ";
		}
	}
}

int main()
{
	printAllDrinks({ "Ivan", 45 });
}

