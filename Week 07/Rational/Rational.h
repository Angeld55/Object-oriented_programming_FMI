#pragma once
#include <fstream>

class Rational
{
	int _nom;
	int _denom;

public:
	Rational();
	Rational(int nom, int denom);

	int getNom() const;
	int getDenom() const;

	void setNom(int nom);
	void setDenom(int denom);

	void rationalize();

	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);
	Rational& operator*=(const Rational& other);
	Rational& operator/=(const Rational& other);

	friend std::ostream& operator<<(std::ostream& os, const Rational& r);
	friend std::istream& operator>>(std::istream& os, Rational& r);

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
