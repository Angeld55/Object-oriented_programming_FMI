#include "Rational.h"



bool operator==(const Rational& lhs, const Rational& rhs)
{
	return lhs.getNom() == rhs.getNom() && lhs.getDenom() == rhs.getDenom();
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational lhsCopy(lhs); //copy constr;
	lhsCopy += rhs;
	return lhsCopy;
}


Rational::Rational() : Rational(1, 1)
{}
Rational::Rational(int nom, int denom)
{
	setNom(nom);
	setDenom(denom);
	rationalize();
}

int Rational::getNom() const
{
	return _nom;
}
int Rational::getDenom() const
{
	return _denom;
}

void Rational::setNom(int nom)
{
	_nom = nom;
}
void Rational::setDenom(int denom)
{
	if (denom == 0)
		denom = 1;
	_denom = denom;
}

namespace {
	unsigned getGcd(unsigned a, unsigned b)
	{
		if (a < b)
			std::swap(a, b);

		while (b != 0)
		{
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
}


void Rational::rationalize()
{
	unsigned gcd = getGcd(abs(_nom), (abs(_denom)));
	_nom /= gcd;
	_denom /= gcd;
}

Rational& Rational::operator+=(const Rational& other)
{
	int oldDenom = _denom;
	_nom *= other._denom;
	_denom *= other._denom;
	int newOtherNom = other._nom * oldDenom;
	_nom += newOtherNom;
	rationalize();
	return *this;
}
Rational& Rational::operator-=(const Rational& other)
{
	Rational otherNeg(other);
	otherNeg._denom *= -1;
	(*this) += otherNeg;
	return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
	_nom *= other._nom;
	_denom *= other._denom;
	rationalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
	return (*this) *= Rational(other._denom, other._nom);

}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	return os << r._nom << " / " << r._denom;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
	return is >> r._nom >> r._denom;
}
