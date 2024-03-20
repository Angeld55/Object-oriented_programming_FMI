#pragma once
#include <climits>
class Interval
{
	int _a = INT_MIN;
	int _b = INT_MAX;
	
public:
	Interval();
	Interval(int a, int b);

	void setA(int a);
	void setB(int b);

	int getA() const;
	int getB() const;

	bool isInInterval(int x) const;

	unsigned getCountCondition(bool (*pred)(int)) const;

	unsigned getPrimesCount() const;
	unsigned getPalindromesCount() const;

	bool isSubinterval(const Interval& other) const;
};

Interval intersectIntervals(const Interval& lhs, const Interval& rhs);