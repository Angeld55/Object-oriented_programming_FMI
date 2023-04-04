#include "Server.h"
#include <cstring>
#include <fstream>
#include <iostream>

void mySwap(User& u1, User& u2) {
	User temp = u1;
	u1 = u2;
	u2 = temp;
}

bool Server::addUser(const char* userName, const char* password) {
	if (usersCount >= MAX_USERS_COUNT) {
		return false;
	}

	users[usersCount] = User(userName, password);
	usersCount++;
	return true;
}

bool Server::removeUser(const char* userName) {
	for (size_t i = 0; i < usersCount; i++) {
		if (strcmp(userName, users[i].getUserName()) == 0) {
			mySwap(users[i], users[usersCount - 1]);
			usersCount--;
			return true;
		}
	}

	return false;
}

bool Server::containsUser(const char* userName) const {
	for (size_t i = 0; i < usersCount; i++) {
		if (strcmp(userName, users[i].getUserName()) == 0) {
			return true;
		}
	}

	return false;
}

void Server::print() const {
	for (size_t i = 0; i < usersCount; i++) {
		std::cout << users[i].getUserName() << std::endl;
	}
}

void Server::printMostAccessedUser() const {
    if(usersCount == 0) {
        return;
    }

    size_t maxIndex = 0;
    for(size_t i = 1; i < usersCount; i++) {
        if(users[i].getAccessCounter() > users[maxIndex].getAccessCounter()) {
            maxIndex = i;
        }
    }

    std::cout << users[maxIndex].getUserName() << std::endl;
}

void Server::writeToFile() const {
	std::ofstream out("Server.txt", std::ios::binary);
	if (!out.is_open()) {
		return;
	}

	out.write((const char*)&usersCount, sizeof(usersCount));
	for (size_t i = 0; i < usersCount; i++) {
		users[i].writeToFile(out);
	}

    out.close();
}

void Server::readFromFile() {
	std::ifstream in("Server.txt", std::ios::binary);
	if (!in.is_open()) {
		return;
	}

	in.read((char*)&usersCount, sizeof(usersCount));
	for (size_t i = 0; i < usersCount; i++) {
		users[i].readFromFile(in);
	}

	in.close();
}