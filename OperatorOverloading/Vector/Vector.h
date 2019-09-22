#include <iostream>
class Vector
{
private:
	int* coordinates;
	int length;
	void CopyFrom(const Vector& other);
	void Free();
public:
	Vector();
	Vector(int len);

	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	int GetLen() const;

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(int);

	friend std::ostream& operator<<(std::ostream&, const Vector& v);
	friend std::istream& operator>>(std::istream&, Vector& v);

	int GetAtIndex(int index) const;
	int& operator[](int index);// оператор за индексиране(като в масивите)  vector a; a[4] -взима четвъртия кординат на вектора
	void print();
};

Vector operator+(const Vector& lhs, const Vector& rhs);// Събиране на два вектора
Vector operator-(const Vector& lhs, const Vector& rhs);// Изваждане на два вектора

int operator%(const Vector& lhs, const Vector& rhs); // Скаларно произведение на два вектора

bool operator||(const Vector& lhs, const Vector& rhs); //проверява дали два вектора са успоредни
bool operator|=(const Vector& lhs, const Vector& rhs); // Дали два вектора са перпендикулярни
