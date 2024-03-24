#pragma once

class Interval
{
private:
	int start = 0;
	int end = 0;

	unsigned countCriteria(bool (*pred)(int)) const;

public:
	Interval() = default;
	Interval(int start, int end);

	unsigned length() const;
	bool isInterval(int num) const;
	unsigned countPrime() const;
	unsigned countPalindrome() const;
	unsigned countUniqueDigits() const;
	bool isPowOfTwo() const;
	Interval intersect(const Interval& other) const;
	bool isSub(const Interval& other) const;
};