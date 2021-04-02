
class Interval
{
	int a;
	int b;

	size_t countNumbersInIntervalCondition(bool(*pred)(int)) const;

public:

	Interval();
	Interval(int a, int b);
	
	int getA() const;
	int getB() const;

	void setA(int a);
	void setB(int b);

	size_t getLength() const;
	bool isMemberOfInterval(int x) const;

	size_t calcPrimeNumbersInTheInterval() const;
	size_t calcPalindromicNumbersInTheInterval() const;
	size_t calcDiffrentDigitNumbersInTheInverval() const;
	bool areStartAndEndPowersOfTwo() const;
	Interval intersect(const Interval& other) const;
	bool isSuperInterval(const Interval& other) const;
};