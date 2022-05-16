#pragma once
#include"vector.hpp"
#include"Page.h"
#include"Pair.hpp"
#include"serialize.h"

class Book {
private:
	string author;
	string title;
	Vector<Pair<string, unsigned>> ratings;		// User name + rate
	Vector<Page> data;							// Pages
	Vector<Pair<string, string>> comments;		// commenter's name + comment

	void addRating(unsigned short r, const string& name);

	void write(unsigned pagesCount);
	void displayBook() const;

	void showComments() const;
	void showRates() const;
	void print() const;
	void displayHelpMenu() const;
public:
	Book() {}
	Book(const string& author, const string& title);

	void writeToFile(std::ofstream& outFile) const;
	void readFromFile(std::ifstream& inFile);
	double getAvarageRating() const;

	friend class Kindle;
};

