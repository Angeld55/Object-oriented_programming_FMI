#include "InformaticsStudent.h"


void InformaticsStudent::CopyFrom(const InformaticsStudent& other)
{
	int len = strlen(other.name);
	name = new char[len + 1];
	strcpy(name, other.name); //copy name
	fn = other.fn; //copy fn
}
void InformaticsStudent::Free()
{
	delete[] name;
	fn = 0;
}

InformaticsStudent::InformaticsStudent()
{
	name = nullptr;
	fn = 0;
}

InformaticsStudent::InformaticsStudent(const char* name, int fn) //При конструктура винаги КОПИРАМЕ подадения стринг за нашния нов обект.
{								 // Това е важно, защото не искаме някой друг да има достъп до него.
	setName(name);
	setFn(fn);
}


InformaticsStudent::InformaticsStudent(const InformaticsStudent& other)
{
	//Използваме функцията, която копира всичко от other в нашия обект.
	CopyFrom(other); 
	
	//Понеже това е конструктор, няма нужда да трия нищо от обекта, понеже няма как да е имало данни тук,защото сега го създаваме.
}

InformaticsStudent& InformaticsStudent::operator=(const InformaticsStudent& other)
{
	//За разлика от при Копи-контструктора , тука е възможно да е имало данни , преди копирането	
	// (възможно е обекта да е съществувал).За това преди да копираме трябва да изтрием, това което е седяло тук.
	// Проверката на 44 ред е с цел да не стане нещо от сорта T1=T1.
	
	if (this != &other)
	{
		Free(); //трия своята памет

		CopyFrom(other); // копирам от другия обект
	}
	return *this;  // Връщаме указател към обекта, в който сме копирали, за може да chain-ваме  T1=T2=T3.
}

InformaticsStudent::~InformaticsStudent()
{
	Free();
}


void InformaticsStudent::setName(const char* name)
{
	delete[] name; //трием данните, които са били тук.
	int len = strlen(name);
	if (hasDigits(name, len))
	{
		this->name[0] = '\0';
		return;
	}
	this->name = new char[len + 1];
	strcpy(this->name, name);


}
void InformaticsStudent::setFn(int fn)
{
	if (fn < 45000 || fn >45999)
		fn = 45000;
	this->fn = fn;
}
const char* InformaticsStudent::getName() const
{
	return name;
}
int InformaticsStudent::getFn() const
{
	return fn;
}

void InformaticsStudent::printStudent()
{
	cout << name << " fn: " << fn << endl;
}
