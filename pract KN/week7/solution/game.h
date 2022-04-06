#ifndef GAME_HEADER
#define GAME_HEADER

#include"player.h"

double newtonSquareRoot(double, int);
bool isPrime(int number);
bool isPowerOfTwo(int number);

class game {
private:
	size_t number;

	void generateNumber();

	void validateBet(double& bet, double cMoney) const;
	void validateNumber(int& number) const;

	double getRate(betType currentBet) const;
public:
	void play(player& p);
};


#endif
