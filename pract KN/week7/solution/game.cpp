#include "game.h"
#include<iostream>
#include<time.h>
#include<cmath>
#include<windows.h>

void game::generateNumber() {
	srand(time(NULL));

	number = rand() % 100 + 1;
}

void game::validateBet(double& bet, double currentMoney) const {
	std::cout << "How much money would you like to bet? " << std::endl
		<< "Your money now: " << currentMoney << std::endl;

	bool fail = false;

	do {
		if (fail)
			std::cout << "Invalid input" << std::endl;

		std::cin >> bet;

		fail = true;

		// Проверява дали сме въвели текстов низ вместо число
		// и поправя потока.
		if (!(bool)(std::cin)) {
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}

	} while (bet > currentMoney || bet < 0);
}

void game::validateNumber(int& num) const {
	std::cout << "Enter your number: ";

	bool fail = false;

	do {
		if (fail)
			std::cout << "Try again" << std::endl;

		std::cin >> num;

		if (!(bool)(std::cin)) {
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}

		fail = true;

	} while (num < 20 || num > 60);
}

double game::getRate(betType currentBet) const {
	double rate = 0;
	int myNumber = 0;

	switch (currentBet) {
	case betType::isEven:
		rate = !(number % 2) ? 0.2 : -1;
		break;
	case betType::isNotEven:
		rate = !(number % 2) ? -1 : 0.2;
		break;
	case betType::isPrime:
		rate = isPrime(number) ? 0.5 : -1;
		break;
	case betType::isPowerOfTwo:
		rate = isPowerOfTwo(number) ? 1 : -1;
		break;
	case betType::isBiggerThan:
		validateNumber(myNumber);
		rate = (myNumber > number) ? 0.25 : -1;
		break;
	case betType::isSmallerThan:
		validateNumber(myNumber);
		rate = (myNumber < number) ? 0.25 : -1;
		break;
	case betType::isTheSameAs:
		validateNumber(myNumber);
		rate = (myNumber == number) ? 10 : -1;
		break;
	}

	return rate;
}

void game::play(player& p) {
	if (p.getAge() < 18) {
		std::cout << "You are too young" << std::endl;
		return;
	}

	char buff[20];
	std::cout << "Enter your password, " << p.getName() << ": ";
	std::cin.getline(buff, 20, '\n');

	if (!p.comparePassword(buff)) {
		std::cout << "Wrong password. Goodbye.";
		return;
	}

	while (!p.isBroke()) {
		double myBet = 0;

		betType currentBet = p.makeBet();

		generateNumber();

		validateBet(myBet, p.getMoney());
		
		p.updateMoney(myBet, getRate(currentBet));

		std::cout << "The number was: " << number << std::endl;
	}

	std::cout << "You lost all your money!" << std::endl;
}


// Bonus:
// https://math.mit.edu/~stevenj/18.335/newton-sqrt.pdf
double newtonSquareRoot(double num, int l = 100) {
	double result = 1;
	double temp = 1;

	for (int i = 0; i < l; i++) {
		temp = 0.5 * (result + num / result);

		if (temp == result && result != 1)
			return result;

		result = temp;
	}

	return result;
}

bool isPrime(int num) {
	// int border = sqrt(num); is fine
	int border = newtonSquareRoot(num);

	for (int i = 2; i <= border; i++)
		if (num % i == 0)
			return false;
	return true;
}

bool isPowerOfTwo(int num) {
	return num != 0 && ((num & (num - 1)) == 0);
}