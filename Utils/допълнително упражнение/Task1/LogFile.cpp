#include "LogFile.h"

void LogFile::readTime(std::ifstream& inFile, Timestamp& obj) const {
	char isLogin;

	inFile >> isLogin;

	obj.isLogin = (isLogin == '+');

	inFile >> obj.hour >> obj.minutes >> obj.seconds;
}


LogFile::LogFile() {
	size = 0;
}

LogFile::LogFile(const char* filePath) {
	std::ifstream inFile(filePath);

	if (!inFile.is_open()) {
		size = 0;
		return;
	}

	inFile >> size;

	for (int i = 0; i < size; i++)
		readTime(inFile, data[i]);
}


int LogFile::getLoginsCountAfterHour(short hours, short minutes, short seconds) const {
	int ctr = 0;
	int totalSeconds = hours * 3600 + minutes * 60 + seconds;
	for (int i = 0; i < size; i++) {
		if (data[i].toSeconds() > totalSeconds) {
			ctr = i + 1;
			break;
		}
	}

	return size - ctr;
}

int LogFile::getLoginsCountBetweenHours(short h1, short m1, short s1, short h2, short m2, short s2) const {
	return getLoginsCountAfterHour(h1, m1, s1) - getLoginsCountAfterHour(h2, m2, s2);
}

int LogFile::getLongestActivePeriod() const {
	int max = 0;
	bool isFirstLogOut = !data[0].isLogin;
	bool isLastLogIn = data[size - 1].isLogin;

	if (isFirstLogOut)
		max = data[0].toSeconds();

	if (isLastLogIn) {
		int lastTimeInterval = 23 * 3600 + 59 * 60 + 59 - data[size - 1].toSeconds();

		if (max < lastTimeInterval)
			max = lastTimeInterval;
	}

	for (int i = isFirstLogOut; i < size - isLastLogIn; i += 2) {
		int diff = data[i + 1].toSeconds() - data[i].toSeconds();
		if (diff > max)
			max = diff;
	}

	return max;
}

bool LogFile::loggedInHour(int hour) const {
	int left = 0;
	int right = size-1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (hour == data[mid].hour) {
			return true;
		}

		if (hour < data[mid].hour) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
}