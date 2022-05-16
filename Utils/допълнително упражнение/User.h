#pragma once

const int NAME_LEN = 20;
const int MAIL_LEN = 12;
const int PASS_LEN = 8;

class User {
private:
	// N символа за име +1 за терминираща нула!
	char name[NAME_LEN + 1];
	char password[PASS_LEN + 1];
	char email[MAIL_LEN + 1];

	void createFileName(char* fileName, const User& other) const;
public:
	User();

	User(const char* n, const char* pass, const char* email);

	void sendMessage(const char* message, const User& u) const;

	void viewMessage(const User& u) const;

	const char* getName() const;
};

