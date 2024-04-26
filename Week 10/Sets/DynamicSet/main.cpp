#include <iostream>
#include "../DynamicSet/DynamicSet.h"
#include <sstream>
#pragma warning (disable : 4996)
class SetByCriteria : public DynamicSet
{
public:
	SetByCriteria(unsigned n, bool(*cr)(unsigned)) : DynamicSet(n)
	{
		fillData(n, cr);
	}

	void setCriteria(bool(*cr)(unsigned))
	{
		fillData(getN(), cr);
	}

private:
	using DynamicSet::add;
	void fillData(unsigned n, bool(*cr)(unsigned))
	{
		for (int i = 0; i <= n; i++)
		{
			if (cr(i))
				add(i);
			else
				remove(i);
		}
	}
};


class SetByString : public DynamicSet
{
public:
	SetByString(unsigned n,  char*&&  str) : DynamicSet(n)
	{
		_str = str;
		str = nullptr;
		fillData();
	}

	SetByString(const SetByString& other) : DynamicSet(other)
	{
		copyFrom(other);
	}

	SetByString& operator=(const SetByString& other)
	{
		if (this != &other)
		{
			DynamicSet::operator=(other);
			free();
			copyFrom(other);
		}
		return *this;
	}

	SetByString(SetByString&& other) : DynamicSet(std::move(other))
	{
		moveFrom(std::move(other));
	}

	SetByString& operator=(SetByString&& other)
	{
		if (this != &other)
		{
			DynamicSet::operator=(std::move(other));
			free();
			moveFrom(std::move(other));
		}
	}

	~SetByString()
	{
		free(); 
	} /// ~DynamicSet


	void setAt(unsigned ind, char ch)
	{
		_str[ind] = ch;
		//..empty the set
		fillData();
	}


private:

	void copyFrom(const SetByString& other) // SetByString
	{
		_str = new char[strlen(other._str) + 1];
		strcpy(_str, other._str);
	}
	void free()
	{
		delete[] _str;
	}
	void moveFrom(SetByString&& other)
	{
		_str = other._str;
		other._str = nullptr;
	}

	void fillData()
	{
		std::stringstream ss(_str);

		while (!ss.eof())
		{
			unsigned n;
			ss >> n;
			add(n);
		}
	}
	char* _str;
};

struct A
{
	int x;
	int f() {}
};
struct B : private A
{
private:
	using A::f;
};

int main()
{

	char str[] = "23432432";
	
	SetByString ss(3333, (char*)"23432432");
	ss.print();
	ss.setAt(5, '0');
	ss.print();

}
