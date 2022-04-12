#pragma once
#include<exception>
class Vector
{
	int* arr = nullptr;
	int size;
	int capacity;

	void resize();
	void free();
	void copyFrom(const Vector&);

public:
	Vector();
	Vector(const Vector&);
	Vector& operator = (const Vector&);
	~Vector();

	void push_back(const int);
	int getSize()const;
	int& operator [](const int);
	const int& operator [](int)const ;



};

