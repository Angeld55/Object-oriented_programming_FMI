#include<iostream>
#include<fstream>
#include<cstring>

// Fix problems with strcpy in visual studio
#pragma warning (disable : 4996)

const int MAX_LENGTH   = 25;
const char FILE_PATH[] = "offers-database.txt";

// Clear std::cin
void flushStream() {
	std::cin.clear();
	std::cin.ignore(255, '\n');
}

struct jobOffer {
	char name[MAX_LENGTH];
	int peopleCount;
	int restDaysCount;
	long long salary;
};

jobOffer createOffer(char name[MAX_LENGTH], int colCount, int restDays, long long salary) {
	jobOffer toReturn;
	strcpy(toReturn.name, name);
	toReturn.peopleCount = colCount;
	toReturn.restDaysCount = restDays;
	toReturn.salary = salary;

	return toReturn;
}

// Read offer from stdin
jobOffer readOffer() {
	std::cout << "Enter company name [max " << MAX_LENGTH << " symbols!]: ";
	char name[MAX_LENGTH];
	int colCount = 0;
	int restDays = 0;
	long long salary = 0;

	std::cin.getline(name, MAX_LENGTH, '\n');

	std::cout << "Add colleague count: ";

	std::cin >> colCount;
	std::cout << "Add rest days: ";
	std::cin >> restDays;
	std::cout << "Add salary: ";
	std::cin >> salary;

	flushStream();
	return createOffer(name, colCount, restDays, salary);
}

void saveOfferToFile(std::ofstream& outFile, const jobOffer& offer) {
	/*int size = strlen(offer.name);
	outFile.write((const char*)&size, sizeof(int));

	outFile.write(offer.name, size * sizeof(char));

	outFile.write((const char*)(&offer.peopleCount), sizeof(offer.peopleCount));

	outFile.write((const char*)(&offer.restDaysCount), sizeof(offer.restDaysCount));

	outFile.write((const char*)(&offer.salary), sizeof(offer.salary));*/
	outFile.write((const char*)&offer, sizeof(offer));
}

void drawLine(int length) {
	for (int i = 0; i < length + 13; i++)
		std::cout << '-';
	std::cout << std::endl;
}

void printOffer(const jobOffer& j) {
	int nameLen = strlen(j.name);
	drawLine(nameLen);
	std::cout << "Company name: " << j.name <<
		"\nPeople in team: " << j.peopleCount << 
		"\nRest days: " << j.restDaysCount << 
		"\nSalary: " << j.salary << std::endl;
	drawLine(nameLen);
	std::cout << std::endl;
}

void readOffer(std::ifstream& inFile, jobOffer& toRead) {
	/*int length = 0;
	inFile.read((char*)&length, sizeof(length));
	inFile.read(toRead.name, length);
	toRead.name[length] = '\0';

	inFile.read((char*)&toRead.peopleCount, sizeof(toRead.peopleCount));
	inFile.read((char*)&toRead.restDaysCount, sizeof(toRead.restDaysCount));
	inFile.read((char*)&toRead.salary, sizeof(toRead.salary));*/
	inFile.read((char*)&toRead, sizeof(toRead));
}

void addOffers(const char* filePath, int n) {
	std::ofstream outFile(filePath, std::ios::binary | std::ios::app);

	if (!outFile) {
		std::cerr << "Problem with oppening file " << filePath;
		return;
	}

	for (int i = 0; i < n; i++) {
		jobOffer toWrite = readOffer();
		saveOfferToFile(outFile, toWrite);
	}

	outFile.close();
}

void filterOffers(const char* filePath, long long minSalary) {
	std::ifstream inFile(filePath, std::ios::binary);

	if (!inFile) {
		std::cerr << "Error";
		return;
	}

	// Same as !inFile.eof()
	while (inFile) {
		jobOffer toRead;
		readOffer(inFile, toRead);
		if (!inFile)
			break;
		if (toRead.salary >= minSalary)
			printOffer(toRead);
	}

	inFile.close();
}

bool searchOffer(const char* filePath, const char* name) {
	std::ifstream inFile(filePath, std::ios::binary);

	if (!inFile) {
		std::cerr << "Error";
		return false;
	}

	while (inFile) {
		jobOffer toRead;
		readOffer(inFile, toRead);
		if (!inFile)
			break;
		if (!strcmp(toRead.name, name)) {
			inFile.close();
			return true;
		}
	}

	inFile.close();
	return false;
}

bool isPerfect(const jobOffer& j, int maxCoworkers, int minVacancyDays, int minSalary) {
	return j.peopleCount <= maxCoworkers && j.restDaysCount >= minVacancyDays && j.salary >= minSalary;
}

void saveOfferToTextFile(std::ofstream& outFile, const jobOffer& j) {
	outFile << j.name << " " << j.peopleCount << " " << j.restDaysCount << " " << j.salary << std::endl;
}

void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
	std::ifstream inFile(filePath, std::ios::binary);
	std::ofstream outFile("perfect.txt", std::ios::app);

	if (!inFile) {
		std::cerr << "Error";
		return;
	}

	while (inFile) {
		jobOffer toRead;
		readOffer(inFile, toRead);
		if (!inFile)
			break;
		if (isPerfect(toRead, maxCoworkers, minVacancyDays, minSalary))
			saveOfferToTextFile(outFile, toRead);
	}

	inFile.close();
}

void printAll(const char* filePath) {
	std::ifstream inFile(filePath, std::ios::binary);

	if (!inFile) {
		std::cerr << "Error";
		return;
	}

	// eq to !inFile.eof()
	while (inFile) {
		jobOffer toRead;
		readOffer(inFile, toRead);
		if (!inFile)
			break;
		printOffer(toRead);
	}

	inFile.close();
}

void runSystem(const char* filePath = FILE_PATH) {
	bool running = true;
	while (running) {
		char c;
		std::cin.get(c);

		switch (c) {
		case 'a':
			flushStream();
			addOffers(filePath, 1);
			break;
		case 'f':
			long long salary;
			std::cin >> salary;
			filterOffers(filePath, salary);
			break;
		case 's':
			flushStream();
			char name[MAX_LENGTH];
			std::cin.getline(name, MAX_LENGTH, '\n');
			if (searchOffer(filePath, name))
				std::cout << "Offer exist\n";
			else
				std::cout << "No such offer\n";
			break;
		case 'q':
			running = false;
			break;
		case 'i':
			printAll(filePath);
			break;
		default:
			break;
		}
	}
}

int main() {
	runSystem();
}
