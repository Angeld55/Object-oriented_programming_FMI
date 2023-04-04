#pragma once
#include "../User/User.h"

const short MAX_USERS_COUNT = 20;

class Server {
private:
	User users[MAX_USERS_COUNT];
	size_t usersCount = 0;
    
public:
	bool addUser(const char* userName, const char* password);
	bool removeUser(const char* userName);
	bool containsUser(const char* userName) const;
	void print() const;
    void printMostAccessedUser() const;

	void writeToFile() const;
	void readFromFile();
};

