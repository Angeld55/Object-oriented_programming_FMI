#pragma once
#include <iostream>
class Complex
{
public:
	Complex();
	Complex(double real, double im);
	
	double getReal() const;
	double getIm() const;
	
	void setReal(double real);
	void setIm(double im);

	Complex getConjugated() const;  //връща комплексно спрегнатото число на текущия обект.

	//assignment operators 
	// a+=b Към а се добавя стойността на b. а се променя , b не се. Операцията  ще върне a за да може да се правят верижни изрази (a+=b+=c)
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);



	//stream opeartors   ( std::cout << c1)  (std::cin >> c1 )
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
	
private:
	double real;
	double im;

};
// a+b. Операторът връща НОВА променлива(Complex), която е резултатът от операцията.
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);
