#pragma once

namespace CustomPredicates {
	bool allValid(int, int, int);
}

class ThreeNumbersWrapperCondition
{
	int a = 0, b = 0, c = 0;
	bool (*predicate) (int, int, int) = CustomPredicates::allValid;

	bool good = true;

	mutable bool isModified = true;
	mutable size_t elementsBeforeCount = 0;

	bool isValidValue(int value) const;
	bool goToNextElement();
	void validateState();
public:
	ThreeNumbersWrapperCondition() = default;
	ThreeNumbersWrapperCondition(bool (*predicate) (int, int, int));
	ThreeNumbersWrapperCondition(int newA, int newB, int newC, bool (*predicate) (int, int, int));

	void setVector(int newA, int newB, int newC);
	void setA(int newA);
	void setB(int newB);
	void setC(int newC);

	int getA() const;
	int getB() const;
	int getC() const;

	void goToNextValidElement();
	int getIndex() const;
	bool isGood() const;

	friend int compare(const ThreeNumbersWrapperCondition& lhs, const ThreeNumbersWrapperCondition& rhs);
};