#pragma once
#include"User.h"

const char FILE_PATH[] = "database.bat";

class chatSystem {
private:
	User data[100];
	size_t size;

	void save() const;

	void read();

	void searchIndexes(int& firstIndex, int& secondIndex, const char* fstName, const char* sndName) const;

public:
	chatSystem();

	void addUser(const User& arg);

	void sendMessage(const char* msg, const char* fstName, const char* sndName) const;

	void viewMessages(const char* sender, const char* reciever) const;

	int getSize() const;

	~chatSystem();

};

