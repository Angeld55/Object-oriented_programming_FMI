#include "chatSystem.h"
#include<cstring>
#include<fstream>

void chatSystem::save() const {
	std::ofstream outFile(FILE_PATH, std::ios::binary);

	outFile.write((const char*)this, sizeof(chatSystem));
}

void chatSystem::read() {
	std::ifstream inFile(FILE_PATH, std::ios::binary);

	inFile.read((char*)this, sizeof(chatSystem));
}

void chatSystem::searchIndexes(int& firstIndex, int& secondIndex, const char* fstName, const char* sndName) const {
	for (int i = 0; i < size; i++) {
		if (strcmp(fstName, data[i].getName()) == 0) {
			firstIndex = i;
		}

		if (strcmp(sndName, data[i].getName()) == 0) {
			secondIndex = i;
		}

		if (firstIndex != -1 && secondIndex != -1)
			break;
	}
}

chatSystem::chatSystem() {
	size = 0;
	read();
}

void chatSystem::addUser(const User& arg) {
	if (size > 99)
		return;

	for (int i = 0; i < size; i++) {
		if (strcmp(arg.getName(), data[i].getName()) == 0) {
			return;
		}
	}

	data[size++] = arg;
}

void chatSystem::sendMessage(const char* msg, const char* fstName, const char* sndName) const {
	int firstIndex = -1;
	int secondIndex = -1;

	searchIndexes(firstIndex, secondIndex, fstName, sndName);

	if (firstIndex == -1 || secondIndex == -1)
		return;

	data[firstIndex].sendMessage(msg, data[secondIndex]);
}

void chatSystem::viewMessages(const char* fstName, const char* sndName) const {
	int firstIndex = -1;
	int secondIndex = -1;

	searchIndexes(firstIndex, secondIndex, fstName, sndName);

	if (firstIndex == -1 || secondIndex == -1)
		return;

	data[firstIndex].viewMessage(data[secondIndex]);
}

int chatSystem::getSize() const {
	return size;
}

chatSystem::~chatSystem() {
	save();
}
