#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include"betType.h"

#pragma warning(disable : 4996)

class player {
private:
	char* name;
	char* password;
	int age;
	double money;

	void free();

	void copy(const player& other);

	void showHelp() const;

	char* copyDynamic(const char* arg) const;

public:
	player() : name(nullptr), password(nullptr), age(0), money(0) {}

	player(const char* name,const char* pass, int age, double money);

	player(const player& other);

	player& operator=(const player& other);

	void setName(const char* newName);

	void setAge(int newAge);

	const char* getName() const;

	void changePassword(const char* newPass, const char* oldPass);

	void updateMoney(double bet, double rate);

	int getAge() const;

	double getMoney() const;

	bool isBroke() const;

	bool comparePassword(const char* pwd) const;

	betType makeBet() const;

	~player();
};

#endif
