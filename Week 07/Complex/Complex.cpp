#include "Complex.h"

Complex::Complex()
{
	real = 0;
	im = 0;
}
Complex::Complex(double real, double im)
{
	this->real = real;
	this->im = im;
}
Complex& Complex::operator+=(const Complex& other)
{
	real += other.real;
	im += other.im;
	return *this;
}
Complex& Complex::operator-=(const Complex& other)
{
	real -= other.real;
	im -= other.im;
	return *this;
}
Complex& Complex::operator*=(const Complex& other)
{
	double oldReal = real;
	real = real*other.real - im*other.im;
	im = oldReal*other.im + im * other.real;
	return *this;
}
Complex& Complex::operator/=(const Complex& other) // a/=b
{
	Complex Conjugated = other.getConjugated(); //взимаме комплексно спрегнатата на другата дроб (b)

	Complex otherCopy(other);// копираме другата (b), за да не я промяняме.

	//Умножаваме двете по комплексно спрегнатата.
	*this *= Conjugated;
	otherCopy *= Conjugated; //Тук трябва да остане само реална част.

	if (otherCopy.real != 0)
	{
		real /= otherCopy.real;
		im /= otherCopy.real;
	}

	return *this;
}


//След дефинирането на +=, -=, *= и /=, можем лесно да дефинираме +, -, * и /, преизползвайки вече написаните опратори.
Complex operator+(const Complex& lhs, const Complex& rhs) { //a+b

	Complex result(lhs); // Създаваме нов обект, който е копие на a (използваме копи-конструктора)
	result += rhs; //към копието на a, добавяме b (Използваме вече дефинирания оператор +=)

	return result;
}

//Операторите -, *, / са аналогични с +. 
Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex result(lhs);
	result -= rhs;

	return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {

	Complex result(lhs);
	result *= rhs;

	return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {

	Complex result(lhs);
	result /= rhs;

	return result;
}

Complex Complex::getConjugated() const
{
	Complex result(*this);
	result.im *= -1;

	return result;
}

double Complex::getReal() const
{
    return real;
}
double Complex::getIm() const
{
    return im;
}

void Complex::setReal(double newReal) 
{
    real = newReal;
}
void Complex::setIm(double newIm) 
{
    im = newIm;
}
	
// за да можем да правим  cout<<c1 или да запазваме във файл и др. 
std::ostream& operator<<(std::ostream& ofs, const Complex& r) {

	return ofs << r.real << ' ' << r.im << 'i';
}

// за да можем да правим cin>>c1 или да четем от файл и др. 
std::istream& operator>>(std::istream& ifs, Complex& r) {

	return ifs >> r.real >> r.im;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
    return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm(); 
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
    return !(lhs == rhs);
}
