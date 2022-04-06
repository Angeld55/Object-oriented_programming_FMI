#include "player.h"
#include<iostream>

void player::free() {
	delete[] name;
	delete[] password;
}

void player::copy(const player& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);

	money = other.money;
	age = other.age;
}
void player::showHelp() const {
	std::cout <<
		"0 for even" << std::endl <<
		"1 for not even" << std::endl <<
		"2 for prime" << std::endl <<
		"3 for power of two" << std::endl <<
		"4 for is less than " << std::endl <<
		"5 for is bigger than" << std::endl <<
		"6 for is equals" << std::endl;
}

player::player(const char* newName, const char* newPass, int age, double money) {
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);

	password = new char[strlen(newPass) + 1];
	strcpy(password, newPass);

	setAge(age);
	this->money = money;
}

player::player(const player& other) {
	copy(other);
}

player& player::operator=(const player& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

void player::setName(const char* newName) {
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void player::setAge(int newAge) {
	if (newAge <= 0 || newAge >= 100) {
		age = 0;
		return;
	}
	age = newAge;
}

const char* player::getName() const {
	return name;
}

void player::changePassword(const char* newPass, const char* oldPass) {
	if (comparePassword(oldPass)) {
		delete[] password;
		password = new char[strlen(newPass) + 1];
		strcpy(password, newPass);
	}
}

void player::updateMoney(double bet, double rate) {
	money += bet * rate;
}

int player::getAge() const {
	return age;
}

double player::getMoney() const {
	return money;
}

bool player::isBroke() const {
	return money <= 0;
}

bool player::comparePassword(const char* pwd) const {
	return pwd != nullptr && (strcmp(password, pwd) == 0);
}

betType player::makeBet() const {
	std::cout << name << ", what is your bet? Press h for help and m to view money.\n";

	while (true) {
		std::cout << ">";
		char ch;

		std::cin >> ch;

		switch (ch) {
		case 'h':
			showHelp();
			break;
		case 'm':
			std::cout << "Money: " << money << std::endl;
			break;
		case '0':
			return betType::isEven;
			break;
		case '1':
			return betType::isNotEven;
			break;
		case '2':
			return betType::isPrime;
			break;
		case '3':
			return betType::isPowerOfTwo;
			break;
		case '4':
			return betType::isSmallerThan;
			break;
		case '5':
			return betType::isBiggerThan;
			break;
		case '6':
			return betType::isTheSameAs;
			break;
		default:
			break;
		}
	}
}

player::~player() {
	free();
}
