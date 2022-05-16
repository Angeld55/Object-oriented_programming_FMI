#include "Kindle.h"

void Kindle::displayUserDialog(User& currentUser) {
	std::cout << "Wellcome, " << currentUser.name << std::endl;
	string cmd;

	while (!(cmd == "exit")) {
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == "read") {
			readBookDialog(currentUser);
		}
		else if (cmd == "rate") {
			rateBookDialog(currentUser);
		}
		else if (cmd == "comment") {
			commentOnBookDialog(currentUser);
		}
		else if (cmd == "write") {
			writeBookDialog(currentUser);
		}
		else if (cmd == "comments") {
			displayCommentsDialog();
		}
		else if (cmd == "view") {
			viewBooks();
		}
		else if (cmd == "rates") {
			displayRatesDialog();
		}
	}

	std::cout << "Exit user dialog" << std::endl;
}

void Kindle::saveFileDialog() const {
	string path;
	std::cout << "Enter path: ";
	std::cin >> path;
	saveToFile(path.c_str());
}

void Kindle::readFileDialog() {
	std::cout << "Enter path: ";
	string path;
	std::cin >> path;
	readFromFile(path.c_str());
}

void Kindle::showHelpDialog() const {
	std::cout << "Write one of the following commands and press enter: " << std::endl
		<< "| login | signup | load | saveas | view | exit" << std::endl <<
		"Press any key to exit" << std::endl;
	std::cin.get();

	std::cin.clear();
	std::cin.ignore(255, '\n');
}

void Kindle::saveToFile(const char* filePath) const {
	std::ofstream outFile(filePath, std::ios::binary);

	if (!outFile)
		return;

	outFile.write("#Ty", 4);

	size_t sizeOfLib = lib.getSize();
	size_t sizeOfUsers = users.getSize();
	// Write lib: 
	outFile.write((const char*)&sizeOfLib, sizeof(sizeOfLib));

	for (size_t i = 0; i < sizeOfLib; i++)
		lib[i].writeToFile(outFile);

	// Save users: 
	outFile.write((const char*)&sizeOfUsers, sizeof(sizeOfUsers));

	for (size_t i = 0; i < sizeOfUsers; i++)
		users[i].writeToFile(outFile);

	std::cout << "Saving success!" << std::endl;
}

void Kindle::readFromFile(const char* filePath) {
	std::ifstream inFile(filePath, std::ios::binary);

	if (!inFile) {
		std::cout << "File does not exist" << std::endl;
		return;
	}

	char typeChecker[4];
	inFile.read(typeChecker, 4);
	if (strcmp(typeChecker, "#Ty") != 0) {
		std::cout << "Invalid file type" << std::endl;
		return;
	}

	size_t sizeOfLib = 0;
	size_t sizeOfUsers = 0;

	// Read lib
	inFile.read((char*)&sizeOfLib, sizeof(sizeOfLib));

	for (size_t i = 0; i < sizeOfLib; i++) {
		lib.pushBack(Book());
		lib[i].readFromFile(inFile);
	}

	// Read users:
	inFile.read((char*)&sizeOfUsers, sizeof(sizeOfUsers));

	for (size_t i = 0; i < sizeOfUsers; i++) {
		users.pushBack(User());
		users[i].readFromFile(inFile);
	}

	std::cout << "Reading success!" << std::endl;
}

int Kindle::findBookIndex(const string& name) const {
	for (size_t i = 0; i < lib.getSize(); i++)
		if (name == lib[i].title)
			return i;
	return -1;
}

int Kindle::findUserIndex(const string& name) const {
	for (size_t i = 0; i < users.getSize(); i++)
		if (name == users[i].name)
			return i;
	return -1;
}

bool Kindle::userReadTheBook(const User& currentUser, int bookIndex) const {
	for (size_t i = 0; i < currentUser.indexesOfBooksRead.getSize(); i++)
		if (currentUser.indexesOfBooksRead[i] == bookIndex)
			return true;
	return false;
}

bool Kindle::existUser(const string& userName) const {
	for (size_t i = 0; i < users.getSize(); i++)
		if (userName == users[i].name)
			return true;
	return false;
}

void Kindle::readBookDialog(User& reader) {
	std::cout << "Which book would you like to read: ";
	string bookName;
	std::cin.ignore();
	bookName.getLine(std::cin);

	int indexOfBook = findBookIndex(bookName);
	if (indexOfBook == -1) {
		std::cout << "No such book" << std::endl;
		return;
	}
	if (!(reader.name == lib[indexOfBook].author) && !userReadTheBook(reader, indexOfBook))
		reader.indexesOfBooksRead.pushBack(indexOfBook);

	lib[indexOfBook].displayBook();
}

void Kindle::rateBookDialog(const User& rater) {
	std::cout << "Enter a book you'd line to rate: ";
	string bookName;
	std::cin.ignore();
	bookName.getLine(std::cin);

	int bookIndex = findBookIndex(bookName);

	if (bookIndex == -1) {
		std::cout << "No such book" << std::endl;
		return;
	}

	if (rater.name == lib[bookIndex].author) {
		std::cout << "You can't rate your own book" << std::endl;
		return;
	}

	unsigned short rate = 0;
	std::cout << "Enter rate: ";
	std::cin >> rate;

	lib[bookIndex].addRating(rate, rater.name);
}

void Kindle::commentOnBookDialog(const User& commenter) {
	std::cout << "Enter a book you would like to comment: ";
	string bookName;
	std::cin.ignore();
	bookName.getLine(std::cin);;

	int index = findBookIndex(bookName);

	if (index == -1) {
		std::cout << "No such book";
		return;
	}

	std::cout << "Enter comment: ";
	string comment;
	comment.getLine(std::cin);
	if (commenter.name == lib[index].author || userReadTheBook(commenter, index)) {
		Pair<string, string> toAdd(commenter.name, std::move(comment));
		lib[index].comments.pushBack(std::move(toAdd));
	}
	else {
		std::cout << "You havent read the book" << std::endl;
		return;
	}
}

void Kindle::writeBookDialog(User& writer) {
	std::cout << "Enter title: ";
	string title;

	std::cin.ignore();

	title.getLine(std::cin);

	Book toAdd(writer.name, title);

	std::cout << "Enter pages count: ";
	unsigned pagesCount = 0;
	std::cin >> pagesCount;

	std::cin.ignore();

	toAdd.write(pagesCount);
	writer.indexesOfBooksWritten.pushBack(lib.getSize());
	lib.pushBack(std::move(toAdd));
}

void Kindle::displayCommentsDialog() const {
	std::cout << "Enter book name: ";
	string bookName;
	std::cin.ignore();
	bookName.getLine(std::cin);;

	int indexOfBook = findBookIndex(bookName);

	if (indexOfBook == -1) {
		std::cout << "No such book" << std::endl;
		return;
	}

	lib[indexOfBook].showComments();
}

void Kindle::displayRatesDialog() const {
	std::cout << "Enter book name: ";
	string bookName;
	std::cin.ignore();
	bookName.getLine(std::cin);

	int indexOfBook = findBookIndex(bookName);

	if (indexOfBook == -1) {
		std::cout << "No such book" << std::endl;
		return;
	}

	lib[indexOfBook].showRates();
}

void Kindle::viewBooks() const {
	for (size_t i = 0; i < lib.getSize(); i++)
		lib[i].print();
}

void Kindle::displayLoginDialog() {
	std::cout << "Enter user name: ";
	string userName;

	std::cin.ignore();

	userName.getLine(std::cin);

	int userIndex = findUserIndex(userName);

	if (userIndex == -1) {
		std::cout << "This user does not exist in our system\n";
		return;
	}
	string pwd;
	std::cout << "Enter password: ";

	pwd.getLine(std::cin);

	if (!(pwd == users[userIndex].password)) {
		std::cout << "Incorrect password.\n";
		return;
	}

	displayUserDialog(users[userIndex]);
}

void Kindle::displaySignupDialog() {
	std::cout << "Enter name: ";
	string name;

	std::cin.ignore();

	name.getLine(std::cin);

	if (existUser(name)) {
		std::cout << "User with that name already exist!" << std::endl;	
		return;
	}

	std::cout << "Enter password: ";
	string password;
	password.getLine(std::cin);

	User toAdd(name, password);
	users.pushBack(std::move(toAdd));
	std::cout << "Successful!" << std::endl;
}


void Kindle::display() {
	string cmd;
	while (!(cmd == "exit")) {
		std::cout << "> ";
		std::cin >> cmd;

		if (cmd == "login" || cmd == "log in") {
			displayLoginDialog();
		}
		else if (cmd == "signup" || cmd == "sign up") {
			displaySignupDialog();
		}
		else if (cmd == "view") {
			viewBooks();
		}
		else if (cmd == "load") {
			readFileDialog();
		}
		else if (cmd == "save") {
			saveFileDialog();
		}
		else if (cmd == "help") {
			showHelpDialog();
		}
		else {
			std::cout << "Invalid command!" << std::endl;
		}
	}
}
