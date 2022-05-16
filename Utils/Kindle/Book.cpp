#include "Book.h"
#include<iostream>

void Book::addRating(unsigned short r, const string& name) {
	if (r > 10)
		return;

	int raterIndex = -1;

	for (size_t i = 0; i < ratings.getSize(); i++) {
		if (name == ratings[i].getFirst()) {
			raterIndex = i;
			break;
		}
	}

	if (raterIndex != -1)
		ratings[raterIndex].setSecond(r);
	else {
		Pair<string, unsigned> toPush(name, r);
		ratings.pushBack(std::move(toPush));
	}
}

void Book::print() const {
	std::cout << title << " by: " << author << std::endl;
}

Book::Book(const string& pAuthor, const string& pTitle) {
	author = pAuthor;
	title = pTitle;
}

void Book::writeToFile(std::ofstream& outFile) const {
	writeString(outFile, author);									// Author
	writeString(outFile, title);									// Title

	// Write pages to file
	int len = data.getSize();
	outFile.write((const char*)&len, sizeof(len));

	for (size_t i = 0; i < len; i++)
		data[i].writeToFile(outFile);

	// Write comments to file: 
	int commentsLen = comments.getSize();
	outFile.write((const char*)&commentsLen, sizeof(commentsLen));
	for (size_t i = 0; i < commentsLen; i++)
		writeCommentsToFile(outFile, comments[i]);

	// Write rates to file:
	int ratesCount = this->ratings.getSize();
	outFile.write((const char*)&ratesCount, sizeof(ratesCount));
	for (size_t i = 0; i < ratesCount; i++)
		writeRatesToFile(outFile, ratings[i]);
}

void Book::readFromFile(std::ifstream& inFile) {
	author = readString(inFile);								// Author
	title = readString(inFile);									// Title
	
	// Read pages:
	int len = 0;
	inFile.read((char*)&len, sizeof(len));

	for (size_t i = 0; i < len; i++) {
		data.pushBack(Page());
		data[i].readFromFile(inFile);
	}

	// Read comments
	int commentsLen = 0;
	inFile.read((char*)&commentsLen, sizeof(commentsLen));
	
	for (size_t i = 0; i < commentsLen; i++) {
		Pair<string, string> toInsert = readCommentsFromFile(inFile);
		comments.pushBack(std::move(toInsert));
	}

	// Read rates from file
	int ratesCount = 0;
	inFile.read((char*)&ratesCount, sizeof(ratesCount));
	for (size_t i = 0; i < ratesCount; i++) {
		Pair<string, unsigned> toPush = readRatesFromFile(inFile);
		ratings.pushBack(std::move(toPush));
	}
}

double Book::getAvarageRating() const {
	double sum = 0;
	for (size_t i = 0; i < ratings.getSize(); i++)
		sum += ratings[i].getSecond();
	
	return sum / (double)(ratings.getSize());
}

void Book::write(unsigned pagesCount) {
	unsigned short lines = 0;

	for (int i = 0; i < pagesCount; i++) {
		std::cout << "Enter lines in page " << i + 1 << ": ";
		std::cin >> lines;
		std::cin.ignore();
		Page toInsert;

		toInsert.write(lines);

		data.pushBack(std::move(toInsert));
	}
}

void Book::displayBook() const {
	bool reading = true;
	bool displayMenu = true;
	unsigned pageNumber = 0;

	char cmd = '\0';
	unsigned pageIndex = 0;

	while (reading) {
		system("cls");
		if (displayMenu)
			displayHelpMenu();

		data[pageIndex].displayPage();

		std::cin.get(cmd);

		switch (cmd) {
		case 'n':
			if (pageIndex < data.getSize() - 1)
				pageIndex++;
			break;
		case 'p':
			if (pageIndex > 0)
				pageIndex--;
			break;
		case 'h':
			displayMenu = !displayMenu;
			break;
		case 'q':
			reading = false;
			break;
		case '@':
			std::cin >> pageNumber;
			if (pageNumber >= 1 && pageNumber < data.getSize() + 1)
				pageIndex = pageNumber - 1;
			break;
		default:
			break;
		}
	}
	system("cls");
}

void Book::showComments() const {
	for (size_t i = 0; i < comments.getSize(); i++)
		std::cout << comments[i].getFirst() << " wrote: " << comments[i].getSecond() << std::endl;
}

void Book::showRates() const {
	for (size_t i = 0; i < ratings.getSize(); i++)
		std::cout << ratings[i].getFirst() << ": " << ratings[i].getSecond() << " start" << std::endl;
	std::cout << std::endl;

	std::cout << "Avarage rate: " << getAvarageRating() << std::endl;
}

void Book::displayHelpMenu() const {
	std::cout << "Entered reader mode." << std::endl
		<< "Press n for next, p for prev." << std::endl << 
		"Press @ + <number> to go to that page" << std::endl << 
		"Press h to hide or show this menu or q to exit" << std::endl;
}
