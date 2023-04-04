#include <iostream>
#include <fstream>
#include "./Server/Server.h"

void main() {
	Server s;
	s.readFromFile();
	//s.addUser("Test", "Test");
	//s.addUser("Test1", "Test1");

	//s.writeToFile();
	s.print();
}