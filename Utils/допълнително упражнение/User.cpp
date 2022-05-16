#include "User.h"
#include<cstring>
#include<fstream>
#include<iostream>

#pragma warning(disable : 4996)

void generatePath(char* path, const char* bigger, const char* smaller) {
	strcpy(path, bigger);
	strcat(path, "-");
	strcat(path, smaller);
	strcat(path, ".bat");
}

void User::createFileName(char* fileName, const User& other) const {
	if (strcmp(name, other.name) == 1) {
		generatePath(fileName, name, other.name);
	}
	else {
		generatePath(fileName, other.name, name);
	}
}

User::User() : name(""), password(""), email(""){}

User::User(const char* n, const char* pass, const char* mail) {
	if (strlen(n) > NAME_LEN || strlen(pass) > PASS_LEN || strlen(mail) > MAIL_LEN) {
		strcpy(name, "");
		strcpy(password, "");
		strcpy(email, "");

		return;
	}

	strcpy(name, n);
	strcpy(password, pass);
	strcpy(email, mail);
}

void User::sendMessage(const char* message, const User& other) const {
	char filePath[50];
	createFileName(filePath, other);

	std::ofstream outFile(filePath, std::ios::binary | std::ios::app);

	if (!outFile.is_open())
		return;

	outFile.write(name, sizeof(name));

	int length = strlen(message);

	outFile.write((const char*)&length, sizeof(length));

	outFile.write(message, length);

	outFile.close();
}

void User::viewMessage(const User& other) const {
	char filePath[50];
	createFileName(filePath, other);

	std::ifstream inFile(filePath, std::ios::binary);

	if (!inFile.is_open())
		return;

	char buff[NAME_LEN + 1]; 

	while (!inFile.eof()) {
		inFile.read(buff, sizeof(buff));

		if (inFile.eof())
			return;

		int length = 0;

		inFile.read((char*)&length, sizeof(length));

		char* msg = new char[length + 1];

		inFile.read(msg, length);

		msg[length] = '\0';

		std::cout << buff << ": " << msg << std::endl;

		delete[] msg;
	}

	inFile.close();
}

const char* User::getName() const {
	return name;
}
