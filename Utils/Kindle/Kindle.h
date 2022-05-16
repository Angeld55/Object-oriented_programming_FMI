#pragma once
#include"vector.hpp"
#include"Book.h"
#include"User.h"
#include"Pair.hpp"
#include<iostream>
#include<cstring>
#include<fstream>

class Kindle {
private:
	Vector<Book> lib;
	Vector<User> users;

	// Helper functions
	int findBookIndex(const string& name) const;
	int findUserIndex(const string& name) const;

	// did user read the book? 
	bool userReadTheBook(const User& currentUser, int bookIndex) const;

	// does user exist?
	bool existUser(const string& userName) const;

	// Functions used by user
	void readBookDialog(User& reader);
	void writeBookDialog(User& writer);

	void rateBookDialog(const User& rater);
	void commentOnBookDialog(const User& commenter);

	void displayCommentsDialog() const;
	void displayRatesDialog() const;

	// TODO: Change book (add or remove page etc.)

	// Functions used by main dialog
	void displayLoginDialog();
	void displaySignupDialog();
	void displayUserDialog(User& currentUser);

	void saveFileDialog() const;
	void readFileDialog();

	void viewBooks() const;
	void showHelpDialog() const;

	// read && write
	void saveToFile(const char* filePath) const;
	void readFromFile(const char* filePath);
public:
	// The only function used by our Kindle class
	void display();
};

