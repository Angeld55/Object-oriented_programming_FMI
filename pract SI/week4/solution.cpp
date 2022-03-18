#include<iostream>
#include<fstream>
#include<cstring>

struct task {
	char* name;
	char* problem;
	int	  points;

	task() : name(nullptr), problem(nullptr), points(0) {}
  
	//task() {
	//	this->name = nullptr;
	//	this->problem = nullptr;
	//	this->points = 0;
	//}

	void setTaskName(const char* nName) {
		delete[] name;						      // Изтриваме старото име за да избегнем отечка на памет

		int length = strlen(nName);			// Вземаме дължината на новото име
		name = new char[length + 1];		// Заделяме точно колкото памет ни трябва

		// Еквивалентно на strcpy, просто копираме символ по символ
		for (int i = 0; i < length; i++)
			name[i] = nName[i];
		name[length] = '\0';
	}

	// Аналогично с setTaskName
	void setTaskProblem(const char* nProblem) {
		delete[] problem;

		int length = strlen(nProblem);
		problem = new char[length + 1];

		for (int i = 0; i < length; i++)
			problem[i] = nProblem[i];
		problem[length] = '\0';
	}

	void writeToFile(std::ofstream& outFile) const {
		int nameLength = strlen(name);
		int problemLength = strlen(problem);

		outFile.write((const char*)&nameLength, sizeof(nameLength));
		outFile.write(name, nameLength);

		outFile.write((const char*)&problemLength, sizeof(problemLength));
		outFile.write(problem, problemLength);

		outFile.write((const char*)&points, sizeof(points));
	}

	void readFromFile(std::ifstream& inFile) {
		int nameLength = 0;
		int problemLength = 0;

		// Какво ще стане ако не изтрием паметта?
		delete[] name;
		delete[] problem;

		inFile.read((char*)&nameLength, sizeof(nameLength));
		name = new char[nameLength + 1];
		inFile.read(name, nameLength);
		name[nameLength] = '\0';

		inFile.read((char*)&problemLength, sizeof(problemLength));
		problem = new char[problemLength + 1];
		inFile.read(problem, problemLength);
		problem[problemLength] = '\0';

		inFile.read((char*)&points, sizeof(points));
	}

	void setPoints(int nPoints) {
		points = nPoints;
	}

	int getPoints() const {
		return points;
	}

	void showTask() const {
		std::cout << "Name: " << name << std::endl <<
			"Problem to be solved: \n" << problem <<
			std::endl << "Points: " << points << std::endl;
	}

	~task() {
		delete[] problem;
		delete[] name;
	}
};

const int TASKS_COUNT = 3;

struct exam {
	task data[TASKS_COUNT];
	int minPoints;

	exam() : minPoints(0) {}

	void setMin(int nMin) {
		// Може да си добавите и допълнителна валидация.
		minPoints = nMin;
	}

	int getMaxPoints() const {
		int result = 0;
		for (int i = 0; i < TASKS_COUNT; i++)
			result += data[i].getPoints();
		return result;
	}

	void writeToFile(const char* filePath) const {
		std::ofstream outFile(filePath, std::ios::binary);

		if (!outFile)
			return;

		for (int i = 0; i < TASKS_COUNT; i++)
			data[i].writeToFile(outFile);
	}

	void readFromFile(const char* filePath) {
		std::ifstream inFile(filePath, std::ios::binary);

		if (!inFile)
			return;

		for (int i = 0; i < TASKS_COUNT; i++)
			data[i].readFromFile(inFile);
	}

	void showTasks() const {
		for (int i = 0; i < TASKS_COUNT; i++)
			data[i].showTask();
	}
};

int main() {
	exam OOP;

	OOP.data[0].setTaskName("First task");
	OOP.data[0].setTaskProblem("Easy problem");
	OOP.data[0].setPoints(0x19);

	OOP.data[1].setTaskName("Second task");
	OOP.data[1].setTaskProblem("Another easy problem");
	OOP.data[1].setPoints(0x19);

	OOP.data[2].setTaskName("Third task");
	OOP.data[2].setTaskProblem("Solvable problem");
	OOP.data[2].setPoints(0x19);

	OOP.setMin(0x4b);

	std::cout << "What we created: " << std::endl;
	OOP.showTasks();

	// Saving to file
	OOP.writeToFile("data.bat");

	exam cloneOOP;
	cloneOOP.readFromFile("data.bat");
	std::cout << std::endl << "What we read: " << std::endl;
	cloneOOP.showTasks();
}
